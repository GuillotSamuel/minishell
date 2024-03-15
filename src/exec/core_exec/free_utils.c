/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:04:08 by azbk              #+#    #+#             */
/*   Updated: 2024/03/15 16:06:04 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
