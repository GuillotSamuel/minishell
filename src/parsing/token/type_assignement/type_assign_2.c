/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_assign_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:42:47 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/20 14:22:34 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	chevron(char *token, t_token *token_list)
{
	(void)token;
	if (ft_strcmp_space(token_list->token, ">") == 0)
		token_list->type = FILE_OUT;
	else if (ft_strcmp_space(token_list->token, ">>") == 0)
		token_list->type = FILE_OUT_OVER;
	else if (ft_strcmp_space(token_list->token, "<") == 0)
		token_list->type = FILE_IN;
	else if (ft_strcmp_space(token_list->token, "<<") == 0)
		token_list->type = HERE_DOC;
}

void	word_chevron(char *prev_token, t_token *token_list)
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
