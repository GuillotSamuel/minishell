/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:56:51 by azbk              #+#    #+#             */
/*   Updated: 2024/03/12 23:47:24 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int is_plus_equal(char *str)
{
	int i;

	i = 0;
	while (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '+')
	{
		if (str[i] == '+')
		{
			if (str[i + 1] == '=')
				return (1);
			else
				return (FAIL);	
		}
		i++;
	}
	return (FAIL);
}

int	ft_export_is_incorrect(char *str)
{
	int	i;

	if (!str || !str[0] || ft_isdigit(str[0]))
		return (FAIL);
	i = 0;
	while (str[i])
	{
        if(str[i] == '+')
        {
            if (str[i + 1] == '=')
            {
                return (OK);
            }
            else
                return (FAIL);
        }
        if (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '+' || str[i] == '=')
            i++;
        else
            return (FAIL);
	}
	return (OK); 
}
