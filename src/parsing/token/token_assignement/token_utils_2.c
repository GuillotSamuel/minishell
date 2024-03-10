/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:57:34 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/20 14:05:03 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static void	end_ctrl_2(int *i, char **str, char c)
{
	(*i)++;
	while ((*str)[*i] && (*str)[*i] != c)
		(*i)++;
}

int	end_ctrl_1(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
		{
			end_ctrl_2(&i, &str, '\'');
			if (str[i] == '\0')
				return (0);
		}
		if (str[i] == '\"')
		{
			end_ctrl_2(&i, &str, '\"');
			if (str[i] == '\0')
				return (0);
		}
		if (str[i] == '|')
			return (1);
		i++;
	}
	return (0);
}
