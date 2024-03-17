/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:04:08 by azbk              #+#    #+#             */
/*   Updated: 2024/03/16 20:38:22 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

void	free_pipes_fd(t_data *data)
{
	int	i;

	i = 0;
	if (!data->pipes_fd)
		return ;
	while (data->pipes_fd[i] != NULL)
	{
		if (data->pipes_fd[i])
		{
			close(data->pipes_fd[i][0]);
			close(data->pipes_fd[i][1]);
			free(data->pipes_fd[i]);
			data->pipes_fd[i] = NULL;
		}
		i++;
	}
	if (data->pipes_fd)
		free(data->pipes_fd);
	data->pipes_fd = NULL;
}

void	free_with_exit(t_data *data)
{
	g_exit_status = 127;
	free(data->pids);
	free_all(data);
	exit(g_exit_status);
}

void	close_fd(t_data *data)
{
	if (data->cmd_list->redir->fd_in > 0)
		close(data->cmd_list->redir->fd_in);
	if (data->cmd_list->redir->fd_out > 1)
		close(data->cmd_list->redir->fd_out);
}
