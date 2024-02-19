/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:04:59 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/15 17:18:38 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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