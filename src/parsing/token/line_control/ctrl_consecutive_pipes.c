/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_consecutive_pipes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:19:24 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/17 16:33:08 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static void	ignore_single_quote(char *line, int *i)
{
	(*i)++;
	while (line[*i] != '\'' && line[*i] != '\0')
		(*i)++;
	if (line[*i] != '\0')
		(*i)++;
}

static void	ignore_double_quote(char *line, int *i)
{
	(*i)++;
	while (line[*i] != '\"' && line[*i] != '\0')
		(*i)++;
	if (line[*i] != '\0')
		(*i)++;
}

int	consecutive_pipes_ctrl(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\"')
			ignore_double_quote(line, &i);
		else if (line[i] == '\'')
			ignore_single_quote(line, &i);
		if (line[i] == '|')
		{
			i++;
			while (line[i] == ' ' && line[i] != '\0')
				i++;
			if (line[i] == '|')
				return (ft_printf("bash: two pipes in a row `||'\n"),
					ERROR_SYNTAX);
		}
		if (line[i] != '\0')
			i++;
	}
	return (SUCCESS);
}
