/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:41:20 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/16 14:07:38 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

static void	command_or_builtin(t_data *data, t_cmd_line *cmd_list)
{
	t_cmd_line	*cmd_list_dup;
	char		*path;

	cmd_list_dup = cmd_list;
	if (check_builtin(cmd_list_dup->args[0]) == 1)
	{
		exec_builtin(cmd_list_dup, data);
		free_all(data);
		free(data->pids);
		exit(0);
	}
	path = ft_cmd_exist(cmd_list_dup->token_list->token);
	if (path != VAR_NOT_FOUND)
	{
		ft_execve_exec(path, cmd_list_dup, data);
	}
	free(data->pids);
	free_all(data);
	g_exit_status = 127;
	exit(0);
}

static void	close_pipes(t_data *data, int num_children)
{
	int	i;

	i = 0;
	while (i < num_children - 1)
	{
		close(data->pipes_fd[i][0]);
		close(data->pipes_fd[i][1]);
		i++;
	}
}

static void	ft_wait_children(int num_children, pid_t *pids)
{
	int	i;

	i = 0;
	while (i < num_children)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
}

static void	create_and_manage_child(t_data *data, t_cmd_line *cmd, pid_t *pid,
		int n)
{
	*pid = fork();
	if (*pid < 0)
	{
		perror("fork");
		free_all(data);
		free(data->pids);
		exit(EXIT_FAILURE);
	}
	else if (*pid == 0)
	{
		if (cmd->redir->fd_in != 0)
			dup2(cmd->redir->fd_in, STDIN_FILENO);
		if (cmd->redir->fd_out != 1)
			dup2(cmd->redir->fd_out, STDOUT_FILENO);
		close_pipes(data, n);
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
		create_and_manage_child(data, cmd_list, &data->pids[i], num_children);
		cmd_list = cmd_list->next;
		i++;
	}
	close_pipes(data, num_children);
	ft_wait_children(num_children, data->pids);
	free_here_doc(data);
	free(data->pids);
}
