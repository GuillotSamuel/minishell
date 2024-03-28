/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:56:51 by azbk              #+#    #+#             */
/*   Updated: 2024/03/28 12:04:09 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	is_plus_equal(char *str)
{
	int	i;

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

	if (!str || !str[0] || ft_isdigit(str[0]) || str[0] == '=' || str[0] == '+')
		return (FAIL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '+')
		{
			if (str[i + 1] == '=')
			{
				return (OK);
			}
			else
				return (FAIL);
		}
		if (str[i] == '=')
			return (OK);
		if (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '+'
			|| str[i] == '=')
			i++;
		else
			return (FAIL);
	}
	return (OK);
}

int	arg_with_egal(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (1);
		i++;
	}
	return (-1);
}

void	ft_export_no_value_with_egal(char *key, t_data *data)
{
	char	*tmp;

	tmp = ft_is_key_in_env(key, data->secret_env);
	if (tmp)
	{
		free(tmp);
		ft_change_value_in_env(key, "\0", data->secret_env);
		return ;
	}
	ft_create_var_env(key, "", data->secret_env);
}
