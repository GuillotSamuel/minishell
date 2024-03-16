/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:52:41 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/16 17:27:52 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	check_token_only_null(t_token *token_list)
{
    t_token	*token_list_dup;

    token_list_dup = token_list;
    while (token_list_dup)
    {
        if (token_list_dup->token != NULL)
            return (ERROR);
        token_list_dup = token_list_dup->next;
    }
    return (SUCCESS);
}

int	check_token_list_after_expand(t_cmd_line **cmd_list)
{
	t_cmd_line	*cmd_list_dup;
	t_token		*token_list_dup;
	t_token		*token_list_dup_prev;
	char		*token;

	cmd_list_dup = *cmd_list;
	while (cmd_list_dup)
	{
		token_list_dup = cmd_list_dup->token_list;
		token_list_dup_prev = NULL;
		if (check_token_only_null(token_list_dup) == ERROR)
		{
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
	}
	return (SUCCESS);
}
