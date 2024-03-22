/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_same_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:56:20 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/22 11:22:18 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

extern int g_exit_status;

int	two_same_redirections(char *line)
{
	int		i;
	char	redirection;

	i = 0;
	while (line[i] != '\0' && line[i + 1] != '\0')
	{
		if ((line[i] == '<' || line[i] == '>'))
		{
			redirection = line[i];
			if (line[i + 1] == ' ' || line[i + 1] == '\t')
			{
				while (line[i] && (line[i] == ' ' || line[i] == '\t'
					|| line[i] == '\n'))
					i++;
				if (line[i] == redirection)
				{
					ft_printf("bash: syntax error near unexpected token `%c'\n", redirection);
					return (ERROR_SYNTAX);
				}
			}
		}
		i++;
	}
	return (SUCCESS);
}
