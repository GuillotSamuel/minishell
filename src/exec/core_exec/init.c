/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:14:54 by azbk              #+#    #+#             */
/*   Updated: 2024/03/13 20:30:46 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int g_exit_status;

int alloc_pipes(t_cmd_line *cmd, int **pipes_fd, int i)
{
	pipes_fd[i] = malloc(sizeof(int) * 2);
	if (!pipes_fd[i])
	{
		free_pipes_fd(pipes_fd, i);
		return (FAIL);
	}
	pipe(pipes_fd[i]);
	if (i != 0)
		cmd->redir->fd_in = pipes_fd[i - 1][0];
	else
		cmd->redir->fd_in = 0;
	if (cmd->next)
		cmd->redir->fd_out = pipes_fd[i][1];
	else
	{
		close(pipes_fd[i][1]);
		close(pipes_fd[i][0]);
		cmd->redir->fd_out = 1;
	}
	return (OK);
}

int init_pipes(t_cmd_line *cmd, size_t nb_cmd)
{
	int i;
	int **pipes_fd;
	t_cmd_line *current;

	current = cmd;
	i = 0;
	pipes_fd = malloc(sizeof(int *) * (nb_cmd));
	if (!pipes_fd)
		return (FAIL);
	while (current)
	{
		if (alloc_pipes(current, pipes_fd, i) == FAIL)
			return (FAIL);	
		current = current->next;
		i++;		
	}
	free_pipes_fd(pipes_fd, nb_cmd);
	return (OK);
}

int start_exec(t_data *data)
{
	t_cmd_line *cmd;
	int nb_cmd;
	
	nb_cmd = 0;

	cmd = data->cmd_list;
	while (cmd)
	{
		if (open_all_redirections(cmd) == -1)
			return (FAIL);
		cmd = cmd->next;
		nb_cmd ++;
	}
    if (nb_cmd == 1 && check_builtin(data->cmd_list->args[0]) == 1)
    {
        if (exec_builtin(data->cmd_list, data) == -1)
            return (FAIL);
    }
    return (OK);
}

void wait_pid(t_data *data, size_t nb_cmb)
{
	size_t i;
	
	i = 0;
	if (nb_cmb == 1)
	{
		return ;
	}
	while (i < nb_cmb)
	{
		waitpid(data->pid[i], &g_exit_status, 0);
		i++;
	}
}

int init_exec(t_data *data)
{
	size_t nb_cmd;
	pid_t *pid;
	t_cmd_line *cmd;

	nb_cmd = 0;
	cmd = data->cmd_list;
	while (cmd)
	{
		cmd = cmd->next;
		nb_cmd++;
	}
	pid = malloc(sizeof(pid_t) * nb_cmd);
	if (!pid)
		return (FAIL);
	data->pid = pid;
	if (init_pipes(data->cmd_list, nb_cmd) == FAIL)
	{
		free(pid);
		return (FAIL);
	}
	start_exec(data);
	wait_pid(data, nb_cmd);
	free(pid);
	return (OK);
}
