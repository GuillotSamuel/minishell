/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:51:01 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/09 11:01:39 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	two_pipes_error(t_data *data)
{
	write(2, "bash: two pipes in a row `||'\n", 30);
	free_all(data);
}

void	exit_error(t_data *data)
{
    ft_printf("Error\n");
	free_all(data);
	exit(1);
}
