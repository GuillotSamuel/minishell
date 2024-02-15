/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:53:31 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/15 21:18:46 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	chevron(char *token, t_token *token_list)
{
	/* TO REMOVE : TEST */
	(void)token;
	/* END TEST */
	if (ft_strcmp_space(token_list->token, ">") == 0)
		token_list->type = FILE_OUT;
	else if (ft_strcmp_space(token_list->token, ">>") == 0)
		token_list->type = FILE_OUT_OVER;
	else if (ft_strcmp_space(token_list->token, "<") == 0)
		token_list->type = FILE_IN;
	else if (ft_strcmp_space(token_list->token, "<<") == 0)
		token_list->type = HERE_DOC;
}

static void	word_chevron(char *prev_token, t_token *token_list)
{
	if (ft_strcmp_space(prev_token, ">") == 0)
		token_list->type = CREAT_FILE;
	else if (ft_strcmp_space(prev_token, ">>") == 0)
		token_list->type = WRITE_FILE;
	else if (ft_strcmp_space(prev_token, "<") == 0)
		token_list->type = OPEN_FILE;
	else if (ft_strcmp_space(prev_token, "<<") == 0)
		token_list->type = LIMITOR;
}

static void	put_type2(t_token *token_list_dup1, t_token *token_list_dup2)
{
	const char *chevron_list[] = {">", ">>", "<", "<<", NULL};
	const char *builtin_list[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};
	
	if (ft_strcmp_array_space(token_list_dup2->token, chevron_list) == 0)
		word_chevron(token_list_dup2->token, token_list_dup1);
	else if (ft_strcmp_array_space(token_list_dup1->token, builtin_list) == 0)
		token_list_dup1->type = BUILTIN;
	else
		token_list_dup1->type = ARG;
}

void	put_type(t_cmd_line **cmd_list, t_data **data)
{
	t_cmd_line	*cmd_list_dup;
	t_token		*token_list_dup1;
	t_token		*token_list_dup2;
	const char	*chevron_list[] = {">", ">>", "<", "<<", NULL};
	const char	*builtin_list[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};

	(void)data; // TO REMOVE
	cmd_list_dup = *cmd_list;
	while (cmd_list_dup)
	{
		token_list_dup1 = cmd_list_dup->token_list;
		token_list_dup2 = NULL;
		while (token_list_dup1)
		{
			if (ft_strcmp_array_space(token_list_dup1->token, chevron_list) == 0)
				chevron(token_list_dup1->token, token_list_dup1);
			else if (token_list_dup2 != NULL)
				put_type2(token_list_dup1, token_list_dup2);
			else if (ft_strcmp_array_space(token_list_dup1->token, builtin_list) == 0)
				token_list_dup1->type = BUILTIN;
			else
				token_list_dup1->type = ARG;
			token_list_dup2 = token_list_dup1;
			token_list_dup1 = token_list_dup1->next;
		}
		cmd_list_dup = cmd_list_dup->next;
	}
}
