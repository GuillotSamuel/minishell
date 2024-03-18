/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_ctrl_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:51:04 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/18 12:12:59 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	ft_space_ctrl_1(char *line, char cmp_str, char cmp_str2)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] && line[i] == cmp_str && line[i + 1] != cmp_str2)
		{
			i++;
			while (line[i] && line[i] == ' ')
				i++;
			if (!line[i])
				break ;
			if (line[i] && line[i] == cmp_str2)
				return (ERROR_SYNTAX);
		}
		i++;
	}
	return (SUCCESS);
}

int	forbiden_char(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\"')
		{
			i++;
			while (line[i] && line[i] != '\"')
				i++;
			if (!line[i])
				break ;
		}
		else if (line[i] == '\'')
		{
			i++;
			while (line[i] && line[i] != '\'')
				i++;
			if (!line[i])
				break ;
		}
		else if (line[i] == ';' || line[i] == '&')
			return (ft_printf("bash: syntax error\n"), ERROR_SYNTAX);
	}
	return (SUCCESS);
}

int	forbiden_consecutive(char *line)
{
	if (/* control_ss1(line) == ERROR_SYNTAX
		||  */control_ss2(line) == ERROR_SYNTAX
		// || control_ii1(line) == ERROR_SYNTAX
		|| control_ii2(line) == ERROR_SYNTAX
		// || control_s1(line) == ERROR_SYNTAX
		|| control_s2(line) == ERROR_SYNTAX
		// || control_i1(line) == ERROR_SYNTAX
		|| control_i2(line) == ERROR_SYNTAX)
		return (ERROR_SYNTAX);
	else
		return (SUCCESS);
}
