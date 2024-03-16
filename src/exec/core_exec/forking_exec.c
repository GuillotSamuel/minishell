/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:41:20 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/16 19:06:34 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

static void	command_or_builtin(t_data *data, t_cmd_line *cmd_list)
{
	t_cmd_line	*cmd_list_dup;
	char		*path;

	cmd_list_dup = cmd_list;
	if (cmd_list->redir->fd_in < 0 || cmd_list->redir->fd_out < 0)
	{
		free_with_exit(data);
	}
	if (check_builtin(cmd_list_dup->args[0]) == 1)
	{
		exec_builtin(cmd_list_dup, data);
		free(data->pids);
		free_all(data);
		exit(g_exit_status);
	}
	ft_check_is_directory(data, cmd_list_dup->args[0]);
	path = ft_cmd_exist(cmd_list_dup->token_list->token);
	if (path != VAR_NOT_FOUND)
	{
		ft_execve_exec(path, cmd_list_dup, data);
	}
	free_with_exit(data);
}



static void	ft_wait_children(int num_children, pid_t *pids)
{
	int		i;
	int		status;
	pid_t	child_pid;

	i = 0;
	while (i < num_children)
	{
		child_pid = waitpid(pids[i], &status, 0);
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		i++;
	}
}

static void	create_and_manage_child(t_data *data, t_cmd_line *cmd, pid_t *pid)
{
	*pid = fork();
	if (*pid < 0)
	{
		perror("fork");
		free(data->pids);
		free_all(data);
		exit(EXIT_FAILURE);
	}
	else if (*pid == 0)
	{
		if (cmd->redir->fd_in != 0)
			dup2(cmd->redir->fd_in, STDIN_FILENO);
		if (cmd->redir->fd_out != 1)
			dup2(cmd->redir->fd_out, STDOUT_FILENO);
		close_fd(data);
		command_or_builtin(data, cmd);
		exit(EXIT_SUCCESS);
	}
}
void	free_here_doc(t_data *data)
{
	t_cmd_line	*cmd;

	cmd = data->cmd_list;
	while (cmd)
	{
		if (cmd->redir->file_here_doc)
		{
			unlink(cmd->redir->file_here_doc);
			free(cmd->redir->file_here_doc);
		}
		cmd->redir->file_here_doc = NULL;
		cmd = cmd->next;
	}
}

void	forking_exec(t_data *data)
{
	t_cmd_line	*cmd_list;
	int			num_children;
	int			i;

	cmd_list = data->cmd_list;
	num_children = cmd_nb(data->cmd_list);
	data->pids = (pid_t *)malloc(sizeof(pid_t) * num_children);
	if (!data->pids)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (cmd_list)
	{
		create_and_manage_child(data, cmd_list, &data->pids[i]);
		cmd_list = cmd_list->next;
		i++;
	}
	close_fd(data);
	ft_wait_children(num_children, data->pids);
	free_here_doc(data);
	free(data->pids);
}
