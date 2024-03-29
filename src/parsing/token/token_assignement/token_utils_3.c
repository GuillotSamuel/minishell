/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:55:35 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/22 12:21:07 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static void	cut_token_2(char *str, t_data *data, int *i)
{
	(*i)++;
	while (str[*i] != '\'' && str[*i] != '\0')
		(*i)++;
	if (str[*i] == '\0')
		exit_error(data);
}

int	cut_token_1(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (((str[i]) == '>' && str[i + 1] == '>')
		|| ((str[i]) == '<' && str[i + 1] == '<'))
		return (i + 2);
	if ((str[i]) == '>' || (str[i]) == '<')
		return (i + 1);
	while (str[i] != ' ' && str[i] != '\0' && str[i] != '>' && str[i] != '<')
	{
		if (str[i] == '\'')
			cut_token_2(str, data, (&i));
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
