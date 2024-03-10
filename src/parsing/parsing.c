/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:12:02 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/10 13:55:35 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parsing(char *line, t_data *data)
{
	t_cmd_line	*cmd_list_dup;
	
	if (token(line, data) == ERROR_G)
		return ;
	//print_token(data); // DEBUG
	expand_all_tokens(data);
	//print_token(data); // DEBUG
	cmd_list_dup = data->cmd_list;
	exec_commands_1(cmd_list_dup, data);
	clear_lists(data);
}
