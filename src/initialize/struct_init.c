/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:00:01 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/15 17:22:23 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_struct(t_data *data)
{
	data->cmd_list = malloc(sizeof(t_cmd_line));
	if (!data->cmd_list)
		exit_error(data);
	data->cmd_list = NULL;
}
