/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:47:10 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/08 19:24:32 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	fill_prev_cmd_node(t_data *data)
{
	t_cmd_line	*cmd_list_dup;
	t_cmd_line	*prev_cmd;

	cmd_list_dup = data->cmd_list;
	prev_cmd = NULL;
	while (cmd_list_dup != NULL)
	{
		cmd_list_dup->prev = prev_cmd;
		prev_cmd = cmd_list_dup;
		cmd_list_dup = cmd_list_dup->next;
	}
}

static void	exec_builtin_or_external(t_cmd_line *cmd, t_data *data)
{
	if (ft_strcmp(cmd->token_list->token, "cd") == 0
		|| ft_strcmp(cmd->token_list->token, "echo") == 0
		|| ft_strcmp(cmd->token_list->token, "env") == 0
		|| ft_strcmp(cmd->token_list->token, "exit") == 0
		|| ft_strcmp(cmd->token_list->token, "export") == 0
		|| ft_strcmp(cmd->token_list->token, "pwd") == 0
		|| ft_strcmp(cmd->token_list->token, "unset") == 0)
		exec_builtins(cmd, data);
	else
		exec_externals(cmd, data);
}

static void	child_process(int pipe_fd[2], t_cmd_line *cmd_list_dup, t_data *data)
{
	ft_printf("child process\n");
	exec_builtin_or_external(cmd_list_dup, data);
	exit (0);
}

static void	parent_process(int pipe_fd[2], t_cmd_line *cmd_list_dup, t_data *data)
{
	ft_printf("parent process\n");
	exec_builtin_or_external(cmd_list_dup, data);
}

void	exec_commands(t_cmd_line *cmd_list_dup, t_data *data)
{
	int			pipe_fd[2];
	pid_t		pid;
	t_cmd_line	*cmd_list_dup_prev;

	convert_env_to_array(data->env, data);
	fill_prev_cmd_node(data);

	if (pipe(pipe_fd) == -1)
		exit_error(data);

	if (cmd_list_dup->next == NULL)
	{
		exec_builtin_or_external(cmd_list_dup, data);
	}
	while (cmd_list_dup != NULL)
	{
		cmd_list_dup_prev = cmd_list_dup;
		cmd_list_dup = cmd_list_dup->next;
	}
	cmd_list_dup = cmd_list_dup_prev;
	while (cmd_list_dup != NULL)
	{
		
		if (cmd_list_dup->prev != NULL)
		{

			pid = fork();
			if (pid == -1)
			{
				exit_error(data);
			}
			else if (pid == 0)
			{
				child_process(pipe_fd, cmd_list_dup, data);
			}
			else if (pid > 0)
			{
				waitpid(pid, NULL, 0);
				ft_printf("PARENT PROCESS\n");
				parent_process(pipe_fd, cmd_list_dup, data);
			}
		}
		cmd_list_dup = cmd_list_dup->prev;
	}
}


