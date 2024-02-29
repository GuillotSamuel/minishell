/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:05:57 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/29 14:10:15 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_cmd_counter(t_data *data)
{
	t_cmd_line	*cmd_list_dup;

	data->cmd_counter = 0;
	cmd_list_dup = data->cmd_list;
	while (cmd_list_dup)
	{
		data->cmd_counter += 1;
		cmd_list_dup = cmd_list_dup->next;
	}
}

void	pipex(t_data *data)
{
	ft_cmd_counter(data);
}
