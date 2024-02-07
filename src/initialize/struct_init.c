/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:00:01 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/07 19:44:28 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	*initialize_t_cmp(t_data **data)
{
	(*data)->cmp = malloc(sizeof(t_cmp));
	if (!(*data)->cmp)
		exit_error (*data);
	(*data)->cmp->chevron_list[0] = ">";
	(*data)->cmp->chevron_list[1] = ">>";
	(*data)->cmp->chevron_list[2] = "<";
	(*data)->cmp->chevron_list[3] = "<<";
	(*data)->cmp->builtin_list[0] = "echo";
	(*data)->cmp->builtin_list[1] = "cd";
	(*data)->cmp->builtin_list[2] = "pwd";
	(*data)->cmp->builtin_list[3] = "export";
	(*data)->cmp->builtin_list[4] = "unset";
	(*data)->cmp->builtin_list[5] = "env";
	(*data)->cmp->builtin_list[6] = "exit";
	(*data)->cmp->start_end_ctrl[0] = "|";
    consec_list_init((*data)->cmp);
}

void	init_struct(t_data *data)
{
	data->cmd_list = malloc(sizeof(t_cmd_line));
	if (!data->cmd_list)
		exit_error(data);
	data->cmd_list = NULL;
	data->cmd_list->token_list = malloc(sizeof(t_token));
	if (!(data->cmd_list)->token_list)
		exit_error(data);
	data->cmd_list->token_list = NULL;
    initialize_t_cmp(&data);
}
