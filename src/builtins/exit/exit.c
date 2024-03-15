/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:07:50 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/15 19:31:08 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

static void	exit_multiple_num(void)
{
	write(2, " too many arguments\n", 20);
	g_exit_status = 1;
}

static void	exit_num_alpha(char **args, t_data *data)
{
	ft_printf("exit\nbash: exit: %s: numeric argument required\n", args[0]);
	g_exit_status = 2;
	free_all(data);
	exit(g_exit_status);
}

static void	exit_one_num(char **args, t_data *data)
{
	ft_printf("exit\n");
	g_exit_status = ft_atoll(args[0]);
	free_all(data);
	exit(g_exit_status);
}

static void	exit_no_args(t_data *data)
{
	ft_printf("exit\n");
	g_exit_status = 0;
	free_all(data);
	exit(g_exit_status);
}

void	ft_exit(char **args, t_data *data)
{
	if (!args[0])
		exit_no_args(data);
	else if (args[0] && args[1])
		exit_multiple_num();
	else if (args[0] && ft_is_positive_llong(args[0]) == SUCCESS)
		exit_one_num(args, data);
	else if (args[0] && ft_is_negative_llong(args[0]) == SUCCESS)
		exit_one_neg_num(data);
	else if (args[0] && ft_is_positive_llong(args[0]) == ERROR_G)
		exit_num_alpha(args, data);
	else
	{
		ft_printf("exit\nbash: exit: %s: numeric argument required\n", args[0]);
		g_exit_status = 2;
		free_all(data);
		exit(g_exit_status);
	}
}
