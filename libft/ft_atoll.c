/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:19:16 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/20 16:21:26 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	int			i;
	int			minus;
	long long	result;

	result = 0;
	minus = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus *= -1;
	while (str[i] > 47 && str[i] < 58)
		result = (result * 10) + (str[i++] - '0');
	return (result * minus);
}
