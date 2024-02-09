/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:04:59 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/09 11:20:19 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	cut_cmd(char *str , t_data *data)
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
				exit_error(data);
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
	i++;
	return (i);
}
