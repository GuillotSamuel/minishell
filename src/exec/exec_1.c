/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:47:10 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/07 13:27:02 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
	exec_builtin_or_external(cmd_list_dup, data);
}

static void	parent_process(int pipe_fd[2], t_cmd_line *cmd_list_dup, t_data *data)
{
	char	buffer[1024];
	int		bytes_read;
	
	(void)cmd_list_dup; // TO REMOVE
	(void)data; // TO REMOVE
	
	close(pipe_fd[1]);
	while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		ft_printf("%s", buffer);
	}
		close(pipe_fd[0]);
}

void	exec_commands(t_cmd_line *cmd_list_dup, t_data *data)
{
	int		pipe_fd[2];
	pid_t	pid;

	convert_env_to_array(data->env, data);
	while (cmd_list_dup != NULL)
	{
		if (cmd_list_dup->next != NULL)
		{
			if (pipe(pipe_fd) == -1)
				exit_error(data);
		}
		pid = fork();
		if (pid == -1)
			exit_error(data);
		else if (pid == 0)
			child_process(pipe_fd, cmd_list_dup, data);
		else
		{
			parent_process(pipe_fd, cmd_list_dup, data);
			wait(NULL);
		}
		cmd_list_dup = cmd_list_dup->next;
	}
}
