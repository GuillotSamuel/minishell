/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:31:19 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/10 19:11:08 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	last_char_ctrl(char *line, t_data *data)
{
	int i;
	const char *cmp[] = {"|", NULL};
	(void)data;	//TO REMOVE
	i = 0;
	while (line[i] != '\0')
		i++;
	i--;
	while (line[i] == ' ')
		i--;
	if (ft_charcmp_array(line[i], cmp) == 0)
	{
		ft_printf("bash: parse error near `%c'\n", line[i]);
		return (ERROR_SYNTAX);
	}
	return (0);
}

static int	first_char_ctrl(char *line, t_data *data)
{
	int i;
	const char *cmp[] = {"|", NULL};
	(void)data;	//TO REMOVE
	i = 0;
	while(line[i] == ' ')
		i++;
	if (ft_charcmp_array(line[i], cmp) == 0)
	{
		ft_printf("bash: parse error near `%c'\n", line[i]);
		return (ERROR_SYNTAX);
	}
	return (0);
}

static int	consecutive_pipes_ctrl(char *line, t_data *data)
{
	int	i;
	(void)data;	//TO REMOVE
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '|')
		{
			i++;
			while (line[i] == ' ')
				i++;
			if (line[i] == '|')
			{
				fflush(stdout);
                ft_printf("bash: two pipes in a row `||'\n");
				return (ERROR_SYNTAX);
			}
		}
		else
			i++;
	}
	return (0);
}

int	line_ctrl(char *line, t_data *data)
{
	if (first_char_ctrl(line, data) == ERROR_SYNTAX
			|| last_char_ctrl(line, data) == ERROR_SYNTAX
			|| consecutive_pipes_ctrl(line, data) == ERROR_SYNTAX)
		return (ERROR_SYNTAX);
	return (0);
}