/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:26:39 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/21 17:43:56 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

void	ft_echo(char **args)
{
	int i;
	int n;

	i = 1;
	n = 0;
	while (args[i] && !ft_strcmp(args[i], "-n"))
	{
		n++;
		i++;
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
