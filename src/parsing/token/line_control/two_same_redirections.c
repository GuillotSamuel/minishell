/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_same_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:56:20 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/22 12:25:25 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

extern int	g_exit_status;

static int	return_two_same_directions_error(char redirection)
{
	g_exit_status = 2;
	ft_printf("bash: syntax error near unexpected token `%c'\n", redirection);
	return (ERROR_SYNTAX);
}

int	two_same_redirections(char *line)
{
	int		i;
	char	redirection;

	i = 0;
	while (line[i] != '\0' && line[i + 1] != '\0')
	{
		ft_ignore_quotes(line, &i);
		if ((line[i] == '<' || line[i] == '>'))
		{
			redirection = line[i];
			if (line[i + 1] == ' ' || line[i + 1] == '\t')
			{
				i += 2;
				while (line[i] && (line[i] == ' ' || line[i] == '\t'
						|| line[i] == '\n'))
					i++;
				if (line[i] == redirection)
					return (return_two_same_directions_error(redirection));
			}
		}
		i++;
	}
	return (SUCCESS);
}
