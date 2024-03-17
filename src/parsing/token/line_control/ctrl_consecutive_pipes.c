/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_consecutive_pipes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:19:24 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/17 13:36:26 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static int	skip_quotes(char *line, int *i)
{
	if (line[*i] == '\"')
	{
		(*i)++;
		while (line[*i] != '\0' && line[*i] != '\"')
			(*i)++;
	}
	else if (line[*i] == '\'')
	{
		(*i)++;
		while (line[*i] != '\0' && line[*i] != '\'')
			(*i)++;
	}
	if (line[*i] == '\0')
		return (ERROR_G);
	else
		return (SUCCESS);
}

int	consecutive_pipes_ctrl(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (skip_quotes(line, &i) == ERROR_G)
			return (SUCCESS);
		if (line[i] == '|')
		{
			i++;
			while (line[i] == ' ')
				i++;
			if (line[i] != '\0' && line[i] == '|')
				return (ft_printf("bash: two pipes in a row `||'\n"),
					ERROR_SYNTAX);
		}
		else
			i++;
	}
	return (SUCCESS);
}
