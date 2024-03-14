/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:04:08 by azbk              #+#    #+#             */
/*   Updated: 2024/03/14 15:24:35 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	free_pipes_fd(t_data *data)
{
	int	i;

	i = 0;
	while (data->pipes_fd[i] != NULL)
	{
		if (data->pipes_fd[i])
		{
			if (data->pipes_fd[i][0] > 0)
				close(data->pipes_fd[i][0]);
			if (data->pipes_fd[i][1] > 0)
				close(data->pipes_fd[i][1]);
			if (data->pipes_fd[i])
				free(data->pipes_fd[i]);
		}
		i++;
	}
	if (data->pipes_fd)
		free(data->pipes_fd);
}
