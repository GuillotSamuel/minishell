/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:41:20 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/15 15:09:02 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	command_or_builtin(t_data *data, t_cmd_line *cmd_list)
{
	t_cmd_line	*cmd_list_dup;
	char		*path;

	cmd_list_dup = cmd_list;
	if (check_builtin(cmd_list_dup->args[0]) == 1)
	{
		exec_builtin(cmd_list_dup, data);
		free_all(data);
		exit(0);
	}
	path = ft_cmd_exist(cmd_list_dup->token_list->token);
	if (path != VAR_NOT_FOUND)
	{
		ft_execve_exec(path, cmd_list_dup, data);
	}
	free_all(data);
	exit(0);
}

void	read_last_pipe(t_data *data)
{
	int	last_pipe_index;
	int		read_end;
	char	buffer[1024];
	ssize_t	bytes_read;

	last_pipe_index = cmd_nb(data->cmd_list) - 1;
	read_end = data->pipes_fd[last_pipe_index][0];
	bytes_read = read(read_end, buffer, sizeof(buffer));
	if (bytes_read > 0)
	{
		write(STDOUT_FILENO, buffer, bytes_read);
	}
	close(read_end);
}

static void	close_all_fd(t_data *data)
{
	int	i;
	int	num_children;

	i = 0;
	num_children = cmd_nb(data->cmd_list);
	while (i < num_children)
	{
		close(data->pipes_fd[i][0]);
		close(data->pipes_fd[i][1]);
		i++;
	}
}

static void	ft_wait_children(int num_children)
{
	int	i;
	int	status;

	i = 0;
	while (i < num_children)
	{
		wait(&status);
		i++;
	}
}

void	forking_exec(t_data *data)
{
	int			i;
	int			num_children;
	t_cmd_line	*cmd_list;
	pid_t		pid;
	int			**pipes_fd;

	i = 0;
	num_children = cmd_nb(data->cmd_list);
	cmd_list = data->cmd_list;
	pipes_fd = data->pipes_fd;
	while (i < num_children)
	{
		pid = fork();
		if (pid < 0)
			free_all(data);
		else if (pid == 0)
		{
			if (i != 0)
				dup2(pipes_fd[i - 1][0], STDIN_FILENO);
			if (i != num_children - 1)
				dup2(pipes_fd[i][1], STDOUT_FILENO);
			close_all_fd(data);
			command_or_builtin(data, cmd_list);
			exit(0);
		}
		i++;
		cmd_list = cmd_list->next;
	}
	close_all_fd(data);
	ft_wait_children(num_children);
}
