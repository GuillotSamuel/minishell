/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:12:02 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/21 18:55:35 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parsing(char *line, t_data *data)
{
	if (token(line, data) == ERROR_G)
		return ;
	/* START OF TEST : display cmds, tokens and types */
	t_data *tmp = data;
 	while (tmp->cmd_list)
	{
		ft_printf("cmd:[%s]\n", tmp->cmd_list->cmd);
		while (tmp->cmd_list->token_list)
		{
			if (tmp->cmd_list->token_list->token)
				ft_printf("token:[%s]\n", tmp->cmd_list->token_list->token);
			else if (tmp->cmd_list->token_list->token[0] == '\0')
				ft_printf("token:[NULL]\n");
			ft_printf("type: %d\n", tmp->cmd_list->token_list->type);
			tmp->cmd_list->token_list = tmp->cmd_list->token_list->next;
		}
		tmp->cmd_list = tmp->cmd_list->next;
	}
	/* END OF TEST */
	clear_lists(data);
}
