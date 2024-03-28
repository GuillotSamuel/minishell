/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:02:24 by emauduit          #+#    #+#             */
/*   Updated: 2024/03/28 12:05:39 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	check_cd_option(char **args)
{
	int	i;

	i = 1;
	if (args[0][0] != '\0')
	{
		if (args[0][0] == '-')
		{
			if (args[0][1] == '-')
				return (OK);
			while (args[0][i])
			{
				if (args[0][i] != '\0')
				{
					ft_putstr_fd("Minishell: cd: ", 2);
					ft_putstr_fd(args[0], 2);
					ft_putstr_fd(": invalid option\n", 2);
					return (-1);
				}
				i++;
			}
		}
	}
	return (OK);
}
