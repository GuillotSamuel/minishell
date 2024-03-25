/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:41:20 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/22 12:40:49 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

static void	command_or_builtin(t_data *data, t_cmd_line *cmd_list)
{
	t_cmd_line	*cmd_list_dup;
	char		*path;

	cmd_list_dup = cmd_list;
	check_empty_token(cmd_list_dup, data);
	if (cmd_list->redir->fd_in < 0 || cmd_list->redir->fd_out < 0)
	{
		free(data->pids);
		free_all(data);
		exit(g_exit_status);
	}
	if (check_builtin(cmd_list_dup->args[0]) == 1)
	{
		exec_builtin(cmd_list_dup, data);
		free(data->pids);
		free_all(data);
		exit(g_exit_status);
	}
	ft_check_is_directory(data, cmd_list_dup->args[0]);
	path = ft_cmd_exist(cmd_list_dup->args[0], data);
	if (path != NULL)
		ft_execve_exec(path, cmd_list_dup, data);
	free(data->pids);
	free_all(data);
	exit(g_exit_status);
}

static void	handle_sigint_child(int sig)
{
	if (sig == 2)
	{
		g_exit_status = 130;
		printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == 3)
	{
		g_exit_status = 131;
		printf("Quit (core dumped)\n");
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	ft_wait_children(int num_children, pid_t *pids)
{
	int	i;
	int	status;

	i = 0;
	signal(SIGQUIT, handle_sigint_child);
	signal(SIGINT, handle_sigint_child);
	while (i < num_children)
	{
		waitpid(pids[i], &status, 0);
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		i++;
	}
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
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
		signal(SIGQUIT, SIG_DFL);
		if (cmd->redir->fd_in != 0)
			dup2(cmd->redir->fd_in, STDIN_FILENO);
		if (cmd->redir->fd_out != 1)
			dup2(cmd->redir->fd_out, STDOUT_FILENO);
		close_fd(data);
		command_or_builtin(data, cmd);
		exit(EXIT_SUCCESS);
	}
}

void	forking_exec(t_data *data)
{
	t_cmd_line	*cmd_list;
	int			num_children;
	int			i;

	cmd_list = data->cmd_list;
	num_children = cmd_nb(data->cmd_list);
	data->pids = malloc(sizeof(pid_t) * num_children);
	if (!data->pids)
	{
		close_fd(data);
		free_here_doc(data);
		return ;
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
