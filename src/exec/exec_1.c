/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:47:10 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/06 17:47:13 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	exec_builtin_or_external(t_cmd_line *cmd, t_data *data)
{
	if (ft_strcmp(cmd->command, "cd") == 0
	|| ft_strcmp(cmd->command, "echo") == 0
	|| ft_strcmp(cmd->command, "env") == 0
	|| ft_strcmp(cmd->command, "exit") == 0
	|| ft_strcmp(cmd->command, "export") == 0
	|| ft_strcmp(cmd->command, "pwd") == 0
	|| ft_strcmp(cmd->command, "unset") == 0)
		exec_builtin(cmd, data);
	else
		exec_external(cmd, data);
}

static void	child_process(int pipe_fd[2], t_cmd_line *cmd_list_dup, t_data *data)
{
	close(pipe_fd[0]);
	    dup2(pipe_fd[1], STDOUT_FILENO);
    execve(cmd_list_dup->command, cmd_list_dup->args, data->env);
}

static void	parent_process(int pipe_fd[2], t_cmd_line *cmd_list_dup, t_data *data)
{
    char buffer[1024];
    int bytes_read;
	    close(pipe_fd[1]);
	while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		printf("%s", buffer);
    }
		close(pipe_fd[0]);
}

void	exec_commands(t_cmd_line *cmd_list_dup, t_data *data)
{
	int	pipe_fd[2];
	pid_t	pid;

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
