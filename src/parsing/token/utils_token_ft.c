/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:55:35 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/19 08:47:57 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	cut_token_2(char *str, t_data *data, int i)
{
	while (str[i] != '\'' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		exit_error(data);
	return (i);
}

int	cut_token_1(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != ' ' && str[i] != '\0')
	{
		if (str[i] == '\'')
		{
			i++;
			i = cut_token_2(str, data, i);
		}
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"' && str[i] != '\0')
				i++;
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
