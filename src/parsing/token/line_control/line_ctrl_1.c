/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_ctrl_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:31:19 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/21 19:58:35 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (SUCCESS);
		i++;
	}
	return (ERROR_SYNTAX);
}

static int	last_char_ctrl(char *line)
{
	int			i;
	const char	*cmp[] = {"|", NULL};

	i = 0;
	while (line[i] != '\0')
		i++;
	i--;
	while (i >= 0 && line[i] == ' ')
		i--;
	if (i >= 0 && ft_charcmp_array(line[i], cmp) == 0)
	{
		ft_printf("bash: parse error near `%c'\n", line[i]);
		return (ERROR_SYNTAX);
	}
	return (SUCCESS);
}

static int	first_char_ctrl(char *line)
{
	int			i;
	const char	*cmp[] = {"|", NULL};

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_charcmp_array(line[i], cmp) == 0)
	{
		ft_printf("bash: parse error near `%c'\n", line[i]);
		return (ERROR_SYNTAX);
	}
	return (SUCCESS);
}

static int	consecutive_pipes_ctrl(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\"')
			while (line[i] != '\"' && line[i] != '\0')
				i++;
		else if (line[i] == '\'')
			while (line[i] != '\'' && line[i] != '\0')
				i++;
		if (line[i] == '|')
		{
			i++;
			while (line[i] == ' ')
				i++;
			if (line[i] == '|')
				return (ft_printf("bash: two pipes in a row `||'\n"),
					ERROR_SYNTAX);
		}
		else
			i++;
	}
	return (SUCCESS);
}

int	line_ctrl(char *line)
{
	if (first_char_ctrl(line) == ERROR_SYNTAX
		|| last_char_ctrl(line) == ERROR_SYNTAX
		|| consecutive_pipes_ctrl(line) == ERROR_SYNTAX
		|| forbiden_consecutive(line) == ERROR_SYNTAX
		|| empty_line(line) == ERROR_SYNTAX
		|| forbiden_char(line) == ERROR_SYNTAX)
		return (ERROR_SYNTAX);
	return (SUCCESS);
}
