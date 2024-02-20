/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_list_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:48:54 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/20 14:05:15 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static void	empty_token_ctrl(char *token,
	t_token **token_list_dup, t_token **token_list_dup_prev)
{
	int	i;

	i = 0;
	while (token[i] == ' ')
		i++;
	if (token[i] == '\0')
		rm_node(token_list_dup, token_list_dup_prev);
}

int	check_token_list(t_cmd_line **cmd_list, t_data **data)
{
	t_cmd_line	*cmd_list_dup;
	t_token		*token_list_dup;
	t_token		*token_list_dup_prev;
	char		*token;

	(void)data;
	cmd_list_dup = *cmd_list;
	while (cmd_list_dup)
	{
		token_list_dup = cmd_list_dup->token_list;
		token_list_dup_prev = NULL;
		while (token_list_dup)
		{
			token = token_list_dup->token;
			empty_token_ctrl(token, &token_list_dup, &token_list_dup_prev);
			if (token_list_dup)
			{
				token_list_dup_prev = token_list_dup;
				token_list_dup = token_list_dup->next;
			}
		}
		cmd_list_dup = cmd_list_dup->next;
	}
	return (SUCCESS);
}
