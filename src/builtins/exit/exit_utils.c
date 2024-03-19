/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:29:48 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/19 17:37:32 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_is_positive_llong(char *str)
{
	unsigned long long	nb;
	int					i;

	nb = 0;
	i = -1;
	if ((str[0] == '+' && ft_strlen(str) > 1) || (str[0] >= '0'
			&& str[0] <= '9'))
		i++;
	else
		return (ERROR_G);
	while (str[++i])
		if (ft_isdigit(str[i]) == 0)
			return (ERROR_G);
	i = -1;
	if (str[0] == '+')
		i++;
	while (str[++i])
	{
		nb = nb * 10 + (str[i] - 48);
		if (nb > LLONG_MAX)
			return (ERROR_G);
	}
	return (SUCCESS);
}

int	ft_is_negative_llong(char *str)
{
	unsigned long long	nb;
	int					i;

	nb = 0;
	i = -1;
	if (str[0] == '-')
		i++;
	else
		return (ERROR_G);
	while (str[++i])
		if (ft_isdigit(str[i]) == 0)
			return (ERROR_G);
	return (SUCCESS);
}

void	exit_one_neg_num(t_data *data, long long nb)
{
	ft_printf("exit\n");
	g_exit_status = 256 - ((nb * -1) % 256);
	free_all(data);
	exit(g_exit_status);
}
