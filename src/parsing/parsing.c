/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:12:02 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/26 16:30:40 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void print_token(t_data *data)
{
	t_cmd_line	*command;
	t_token		*current_token;
	int i = 0;
	
	command = data->cmd_list;
	while (command)
	{
		current_token = command->token_list;
		while (current_token)
		{
			printf("token[%d] = %s\n", ++i, current_token->token);
			current_token = current_token->next;
		}
		command = command->next;
	}
}

void	parsing(char *line, t_data *data)
{
	if (token(line, data) == ERROR_G)
		return ;
	//print_token(data);
	expand_all_tokens(data);
	print_token(data);
	clear_lists(data);
}
