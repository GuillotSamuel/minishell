/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:47:10 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/10 14:17:52 by sguillot         ###   ########.fr       */
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
	(void)pipe_fd;
	ft_printf("\nchild process\n");
	exec_builtin_or_external(cmd_list_dup, data);
}

static void	parent_process(int pipe_fd[2], t_cmd_line *cmd_list_dup, t_data *data)
{
	(void)pipe_fd;
	ft_printf("\nparent process\n");
	exec_builtin_or_external(cmd_list_dup, data);
}

/* void	exec_commands(t_cmd_line *cmd_list_dup, t_data *data)
{
	int			pipe_fd[2];
	pid_t		pid;
	t_cmd_line	*cmd_list_dup_prev;



	if (pipe(pipe_fd) == -1)
		exit_error(data);

	if (cmd_list_dup->next == NULL)
	{
		exec_builtin_or_external(cmd_list_dup, data);
	}
	else
	{
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
				if (pid < 0)
				{
					exit_error(data);
				}
				else if (pid == 0)
				{
					child_process(pipe_fd, cmd_list_dup, data);
				}
				else
				{
					waitpid(pid, NULL, 0);
					//ft_printf("PARENT PROCESS\n");
					parent_process(pipe_fd, cmd_list_dup, data);
				}
			}
			cmd_list_dup = cmd_list_dup->prev;
		}
	}	
} */

static void	exec_commands_2(t_cmd_line *cmd_list_dup, t_data *data, int pipe_fd[2], int cmd_count)
{
	pid_t		pid;
	
	if (cmd_count == 0)
	{
		ft_printf("cmd_list_dup->cmd = %s\n", cmd_list_dup->cmd);
		child_process(pipe_fd, cmd_list_dup, data);
		exit(0);
	}
	pid = fork();
	if (pid < 0)
	{
		exit_error(data);
	}
	if (pid == 0)
	{
		exec_commands_2(cmd_list_dup->prev, data, pipe_fd, cmd_count - 1);
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, 0);
		ft_printf("cmd_list_dup->cmd = %s\n", cmd_list_dup->cmd);
		parent_process(pipe_fd, cmd_list_dup, data);
	}
}

void	exec_commands_1(t_cmd_line *cmd_list_dup, t_data *data)
{
	t_cmd_line	*cmd_list_dup_prev;
	int			pipe_fd[2];
	int			cmd_count;

	convert_env_to_array(data->env, data);
	fill_prev_cmd_node(data);
	while (cmd_list_dup != NULL)
	{
		cmd_list_dup_prev = cmd_list_dup;
		cmd_list_dup = cmd_list_dup->next;
		cmd_count++;
	}
	if (pipe(pipe_fd) == -1)
		exit_error(data);
	exec_commands_2(cmd_list_dup_prev, data, pipe_fd, cmd_count);
}
