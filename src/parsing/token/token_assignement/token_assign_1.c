/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_assign_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:54:54 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/22 12:07:36 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static void	create_token_5_exit_error(t_data **data, char *tok_dup)
{
	free(tok_dup);
	exit_error(*data);
}

static void	create_token_4(int *i, char **tok_dup, t_cmd_line **cur_cmd)
{
	*i = 0;
	*tok_dup = ft_strdup((*cur_cmd)->cmd);
}

static int	create_token_3(char **token, char **token_dup, int *i,
	t_cmd_line **current_cmd)
{
	*token = malloc(sizeof(char) * (*i + 1));
	if (!*token)
		return (ERROR_G);
	*token = ft_memset(*token, '\0', *i + 1);
	ft_strlcpy(*token, *token_dup, *i + 1);
	if ((*current_cmd)->token_list == NULL)
		(*current_cmd)->token_list = ft_stacknew_token(*token);
	else
		ft_stackaddback_token(&((*current_cmd)->token_list),
			ft_stacknew_token(*token));
	*token_dup = ft_remove_nchar_from_str_2(*token_dup, *i);
	*i = 0;
	return (SUCCESS);
}

static int	create_token_2(char **token, char *token_dup, int i,
	t_cmd_line *current_cmd)
{
	*token = malloc(sizeof(char) * (i + 2));
	if (!*token)
		return (ERROR_G);
	*token = ft_memset(*token, '\0', i + 2);
	ft_strlcpy(*token, token_dup, i + 1);
	if (current_cmd->token_list == NULL)
		current_cmd->token_list = ft_stacknew_token(*token);
	else
		ft_stackaddback_token(&(current_cmd->token_list),
			ft_stacknew_token(*token));
	return (SUCCESS);
}

void	create_token_1(t_cmd_line **cmd_list, t_data **data)
{
	t_cmd_line	*cur_cmd;
	char		*token;
	char		*tok_dup;
	int			i;

	cur_cmd = *cmd_list;
	while (cur_cmd)
	{
		create_token_4(&i, &tok_dup, &cur_cmd);
		while (tok_dup[i] != '\0')
		{
			if (i == cut_token_1(tok_dup, (*data)))
			{
				if (create_token_3(&token, &tok_dup, &i, &cur_cmd) == ERROR_G)
					create_token_5_exit_error(data, tok_dup);
			}
			else
				i++;
		}
		if (i > 0)
			if (create_token_2(&token, tok_dup, i, cur_cmd) == ERROR_G)
				create_token_5_exit_error(data, tok_dup);
		cur_cmd = cur_cmd->next;
		free(tok_dup);
	}
}
