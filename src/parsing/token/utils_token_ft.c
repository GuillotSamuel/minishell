/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:55:35 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/12 15:10:32 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int cut_token(char *str, t_data *data)
{
	int i;

	i = 0;
	while (str[i] == ' ') // REVOIR LES WHITE SPACES
		i++;
	while (str[i] != ' ' && str[i] != '\0') // REVOIR LES WHITE SPACES
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i] != '\0')
			{
				i++;
			}
			if (str[i] == '\0')
				exit_error(data);
		}
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"' && str[i] != '\0')
			{
				i++;
			}
			if (str[i] == '\0')
				exit_error(data);
		}
		i++;
	}
	return (i);
}

void	rm_node(t_token **token_list_dup, t_token **token_list_dup_prev)
{
	t_token	*temp;

	if (*token_list_dup_prev == NULL)
	{
		temp = (*token_list_dup)->next;
		free((*token_list_dup)->token);
		free(*token_list_dup);
		*token_list_dup = temp;
	}
	else if ((*token_list_dup)->next == NULL)
	{
		(*token_list_dup_prev)->next = NULL;
		free((*token_list_dup)->token);
		free(*token_list_dup);
		*token_list_dup = NULL;
	}
	else
	{
		(*token_list_dup_prev)->next = (*token_list_dup)->next;
		free((*token_list_dup)->token);
		free(*token_list_dup);
		*token_list_dup = (*token_list_dup_prev)->next;
	}
}
