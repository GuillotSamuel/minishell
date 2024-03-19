/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:26:39 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/19 14:02:23 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

static int	only_n(char *str)
{
	int	i;

	i = 1;
	while (str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

static int	count_n(char **args)
{
	int	i;

	i = 1;
	while (args[i] && args[i][0] == '-' && args[i][1] == 'n')
	{
		if (only_n(args[i]))
			i++;
		else
			return (i);
	}
	return (i);
}

void	ft_echo(char **args)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (args[1] && args[1][0] == '-' && args[1][1] == 'n')
	{
		if (only_n(args[1]))
		{
			n = 1;
			i = count_n(args);
		}
	}
	while (args[i])
	{
		ft_printf("%s", args[i]);
		if (args[i + 1])
			ft_printf(" ");
		i++;
	}
	if (!n)
		ft_printf("\n");
	g_exit_status = 0;
}
