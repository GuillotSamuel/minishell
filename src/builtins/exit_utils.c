/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:29:48 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/20 17:32:03 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_positive_llong(char *str)
{
	unsigned long long	nb;
	int					i;

	nb = 0;
	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) == 0)
			return (ERROR_G);
	i = -1;
	while (str[++i])
	{
		nb = nb * 10 + (str[i] - 48);
		if (nb > LLONG_MAX)
			return (ERROR_G);
	}
	return (SUCCESS);
}
