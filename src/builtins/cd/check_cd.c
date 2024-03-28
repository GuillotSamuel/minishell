/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:02:24 by emauduit          #+#    #+#             */
/*   Updated: 2024/03/28 12:57:29 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	error_cd(char *arg)
{
	ft_putstr_fd("Minishell: cd: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": invalid option\n", 2);
	return (FAIL);
}

int	check_cd_option(char **args)
{
	int	i;

	i = 1;
	if (args[0][0] != '\0')
	{
		if (args[0][0] == '-' && args[0][1] == '\0')
			return (OK);
		if (args[0][0] == '-' && args[0][1] != '\0')
			return (error_cd(args[0]));
	}
	return (OK);
}
