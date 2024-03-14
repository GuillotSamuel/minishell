/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:04:08 by azbk              #+#    #+#             */
/*   Updated: 2024/03/13 19:50:27 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	free_pipes_fd(int **pipes_fd, int nb_pipes)
{
	int	i;

	i = 0;
	while (i < nb_pipes)
	{
		if (pipes_fd[i])
		{
			if (pipes_fd[i][0] > 0)
				close(pipes_fd[i][0]);
			if (pipes_fd[i][1] > 0)
				close(pipes_fd[i][1]);
			free(pipes_fd[i]);
		}
		i++;
	}
	free(pipes_fd);
}
