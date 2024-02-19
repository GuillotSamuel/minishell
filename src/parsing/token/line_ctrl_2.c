/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_ctrl_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:51:04 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/19 08:16:49 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
			if (line[i] && line[i] == cmp_str2)
				return (ERROR_SYNTAX);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_strcmp_array_space_3(char *line, const char **cmp_arr, char *cmp_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (cmp_arr[j] && cmp_arr[j][0] != line[i])
			j++;
		if (cmp_arr[j] && cmp_arr[j][0] == line[i])
		{
			i++;
			if ((ft_strlen(cmp_str) == 1 && line[i] != cmp_str[0])
				|| ft_strlen(cmp_str) == 2)
			{
				while (line[i] && line[i] == ' ')
					i++;
				if (ft_strlen(cmp_str) == 2 && line[i] && line[i + 1]
					&& line[i] == cmp_str[0] && line[i + 1] == cmp_str[1])
					return (2);
				else if (cmp_arr[j] && ft_strlen(cmp_str) == 1
					&& line[i] && line[i] == cmp_str[0])
					return (1);
			}
		}
		j = 0;
		i++;
	}
	return (SUCCESS);
}

int	ft_strcmp_array_space_2(char *line, const char **cmp_arr, char *cmp_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] && line[i + 1] && ft_strlen(cmp_str) == 2
			&& line[i] == cmp_str[0] && line[i + 1] == cmp_str[1])
		{
			i += 2;
			while (line[i] && line[i] == ' ')
				i++;
			while (cmp_arr[j] && cmp_arr[j][0] != line[i])
				j++;
			if (cmp_arr[j] && cmp_arr[j][0] == line[i]
				&& (line[i + 1] == '<' || line[i + 1] == '>'))
				return (-(j + 1));
			else if (cmp_arr[j] && cmp_arr[j][0] == line[i])
				return (j + 1);
			j = 0;
		}
		else if (line[i] && line[i] == cmp_str[0] && ft_strlen(cmp_str) == 1)
		{
			i++;
			if (line[i] == cmp_str[0])
				i++;
			while (line[i] && line[i] == ' ')
				i++;
			while (cmp_arr[j] && cmp_arr[j][0] != line[i])
				j++;
			if (cmp_arr[j] && cmp_arr[j][0] == line[i]
				&& (line[i + 1] == '<' || line[i + 1] == '>'))
				return (-(j + 1));
			else if (cmp_arr[j] && cmp_arr[j][0] == line[i])
				return (j + 1);
			j = 0;
		}
		i++;
	}
	return (SUCCESS);
}

int	forbiden_consecutive(char *line)
{
	if (control_ss1(line) == ERROR_SYNTAX
		|| control_ss2(line) == ERROR_SYNTAX
		|| control_ii1(line) == ERROR_SYNTAX
		|| control_ii2(line) == ERROR_SYNTAX
		|| control_s1(line) == ERROR_SYNTAX
		|| control_s2(line) == ERROR_SYNTAX
		|| control_i1(line) == ERROR_SYNTAX
		|| control_i2(line) == ERROR_SYNTAX)
		return (ERROR_SYNTAX);
	else
		return (SUCCESS);
}
