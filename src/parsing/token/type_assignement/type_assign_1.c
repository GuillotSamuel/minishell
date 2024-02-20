/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_assign_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:53:31 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/20 14:55:57 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static void	put_type_4(t_token **token_list_dup1, t_token **token_list_dup2)
{
	*token_list_dup2 = *token_list_dup1;
	*token_list_dup1 = (*token_list_dup1)->next;
}

static void	put_type_3(t_token **token_list_dup1, t_token **token_list_dup2,
	t_cmd_line **cmd_list_dup)
{
	*token_list_dup1 = (*cmd_list_dup)->token_list;
	*token_list_dup2 = NULL;
}

static void	put_type_2(t_token *token_list_dup1, t_token *token_list_dup2)
{
	const char	*chevron_list[] = {">", ">>", "<", "<<", NULL};
	const char	*builtin_list[]
		= {"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};

	if (ft_strcmp_array_space(token_list_dup2->token, chevron_list) == 0)
		word_chevron(token_list_dup2->token, token_list_dup1);
	else if (ft_strcmp_array_space(token_list_dup1->token, builtin_list) == 0)
		token_list_dup1->type = BUILTIN;
	else
		token_list_dup1->type = ARG;
}

void	put_type_1(t_cmd_line **cmd_list)
{
	t_cmd_line	*cmd_list_dup;
	t_token		*token_list_dup1;
	t_token		*token_list_dup2;
	const char	*chev_list[] = {">", ">>", "<", "<<", NULL};
	const char	*b_list[]
		= {"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};

	cmd_list_dup = *cmd_list;
	while (cmd_list_dup)
	{
		put_type_3(&token_list_dup1, &token_list_dup2, &cmd_list_dup);
		while (token_list_dup1)
		{
			if (ft_strcmp_array_space(token_list_dup1->token, chev_list) == 0)
				chevron(token_list_dup1->token, token_list_dup1);
			else if (token_list_dup2 != NULL)
				put_type_2(token_list_dup1, token_list_dup2);
			else if (ft_strcmp_array_space(token_list_dup1->token, b_list) == 0)
				token_list_dup1->type = BUILTIN;
			else
				token_list_dup1->type = ARG;
			put_type_4(&token_list_dup1, &token_list_dup2);
		}
		cmd_list_dup = cmd_list_dup->next;
	}
}
