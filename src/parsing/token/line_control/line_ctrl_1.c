/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_ctrl_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:31:19 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/22 12:24:26 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

extern int	g_exit_status;

static int	forbiden_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		ft_ignore_quotes(line, &i);
		if ((line[i] == '>' || line[i] == '<') && line[i + 1] != '\0')
		{
			i++;
			while (line[i] == '\n' || line[i] == ' ' || line[i] == '\t')
			{
				ft_ignore_quotes(line, &i);
				if (line[i] == '\n')
				{
					ft_printf("bash: syntax error near"
						"unexpected token `newline'\n");
					return (ERROR_SYNTAX);
				}
				i++;
			}
		}
		i++;
	}
	return (SUCCESS);
}

static int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (SUCCESS);
		i++;
	}
	return (ERROR_SYNTAX);
}

static int	last_char_ctrl(char *line)
{
	int			i;
	const char	*cmp[] = {"|", ">", "<", NULL};

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

int	line_ctrl(char *line)
{
	if (empty_line(line) == ERROR_SYNTAX)
		return (ERROR_SYNTAX);
	else if (first_char_ctrl(line) == ERROR_SYNTAX
		|| last_char_ctrl(line) == ERROR_SYNTAX
		|| consecutive_pipes_ctrl(line) == ERROR_SYNTAX
		|| forbiden_newline(line) == ERROR_SYNTAX
		|| forbiden_consecutive(line) == ERROR_SYNTAX
		|| two_same_redirections(line) == ERROR_SYNTAX
		|| forbiden_char(line) == ERROR_SYNTAX)
	{
		g_exit_status = 2;
		return (ERROR_SYNTAX);
	}
	return (SUCCESS);
}
