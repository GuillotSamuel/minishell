/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_assign_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:04:59 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/08 13:40:50 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	cut_cmd(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '|' && str[i] != '\0')
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (ft_printf("bash: parse error near `\''\n"), ERROR_G);
		}
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"' && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (ft_printf("bash: parse error near `\"'\n"), ERROR_G);
		}
		i++;
	}
	i++;
	return (i);
}

t_cmd_line	*ft_stacknew_cmd(char *content)
{
	t_cmd_line	*new_element;

	new_element = (t_cmd_line *)malloc(sizeof(t_cmd_line));
	if (!new_element)
		return (NULL);
	new_element->cmd = content;
	new_element->token_list = NULL;
	new_element->args = NULL;
	new_element->next = NULL;
	new_element->redir = NULL;
	return (new_element);
}

void	ft_stackaddback_cmd(t_cmd_line **line, t_cmd_line *new)
{
	t_cmd_line	*tmp;

	if (*line == NULL)
		*line = new;
	else
	{
		tmp = *line;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	new->next = NULL;
}
