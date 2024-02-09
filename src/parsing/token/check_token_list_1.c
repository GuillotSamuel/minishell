/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_list_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:48:54 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/09 15:47:07 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/* static void	ft_print_consec_token(char *token)
{
	int		i;

	i = 0;
	while (token[i] == ' ')
		i++;
	ft_printf("bash: syntax error near unexpected token `%c", token[i]);
	if (token[i + 1] != '\0')
	{
		if (token[i + 1] == '<' || token[i + 1] == '>')
			ft_printf("%c'", token[i]);
		else
			ft_printf("'\n");
	}
	else
		ft_printf("'\n");
}

static int	forbiden_consecutive_token_2(t_token **token_list_dup, t_data **data)
{
	if (ft_array_cmp_consec(token_list_dup, data) == 1)
		return (ft_print_consec_token((*token_list_dup)->next->token), 1);
	return (0);
}

static int	forbiden_consecutive_token(t_token **token_list_dup, t_data **data)
{
	t_token **token_list_dup2;
	
	token_list_dup2 = token_list_dup;
	if ((*token_list_dup2)->next == NULL)
		return (0);
	while ((*token_list_dup2)->next)
	{
		if (ft_strcmp_space((*token_list_dup2)->token, "<<") == 0)
			return (forbiden_consecutive_token_2(token_list_dup2, data));
		else if (ft_strcmp_space((*token_list_dup2)->token, "<") == 0)
			return (forbiden_consecutive_token_2(token_list_dup2, data));
		else if (ft_strcmp_space((*token_list_dup2)->token, ">>") == 0)
			return (forbiden_consecutive_token_2(token_list_dup2, data));
		else if (ft_strcmp_space((*token_list_dup2)->token, ">") == 0)
			return (forbiden_consecutive_token_2(token_list_dup2, data));
		(*token_list_dup2) = (*token_list_dup2)->next;
	}
	return (0);
} */

static void	empty_token_ctrl(char *token, t_token **token_list_dup, t_token **token_list_dup_prev)
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
/* 		if (forbiden_consecutive_token(&token_list_dup, data) == 1)
			return (-1); */
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
    return (0);
}
