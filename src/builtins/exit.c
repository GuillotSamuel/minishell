/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:07:50 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/20 17:31:54 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	g_exit_status = 0;

static void	exit_multiple_num(void)
{
	ft_printf("exit\nbash: exit: too many arguments\n");
	g_exit_status = 1;
}

static void	exit_num_alpha(char **args)
{
	ft_printf("exit\nbash: exit: %s: numeric argument required\n", args[0]);
	g_exit_status = 2;
	exit(g_exit_status);
}

static void	exit_one_num(char **args)
{
	ft_printf("exit\n");
	g_exit_status = ft_atoll(args[0]);
	exit(g_exit_status);
}

static void	exit_no_args(void)
{
	ft_printf("exit\n");
	g_exit_status = 0;
	exit(g_exit_status);
}

void	ft_exit(char **args)
{
	if (!args[0])
		exit_no_args();
	else if (args[0] && args[1])
		exit_multiple_num();
	else if (args[0] && ft_is_positive_llong(args[0]) == ERROR_G)
		exit_num_alpha(args);
	else if (args[0] && ft_is_positive_llong(args[0]) == SUCCESS)
		exit_one_num(args);
	else
	{
		ft_printf("exit\nbash: exit: %s: numeric argument required\n", args[0]);
		g_exit_status = 2;
		exit(g_exit_status);
	}
}
