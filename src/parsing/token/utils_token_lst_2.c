/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_lst_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:35:02 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/19 10:35:39 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_token	*ft_stacknew_token(char *content)
{
	t_token	*new_element;

	new_element = (t_token *)malloc(sizeof(t_token));
	if (!new_element)
		return (NULL);
	new_element->token = content;
	new_element->next = NULL;
	return (new_element);
}

void	ft_stackaddback_token(t_token **lst, t_token *new)
{
	t_token	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}
