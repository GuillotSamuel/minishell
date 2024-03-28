/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:29:14 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/28 12:04:28 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	ft_export_plus_equal(char *key, char *value, t_data *data)
{
	char	*str;

	str = ft_is_key_in_env(key, data->env);
	if (str)
	{
		ft_add_value_in_env(key, value, str, data->env);
		free(str);
	}
	else
	{
		ft_create_var_env(key, value, data->env);
	}
	str = ft_is_key_in_env(key, data->secret_env);
	if (str)
	{
		ft_add_value_in_env(key, value, str, data->secret_env);
		free(str);
	}
	else
	{
		ft_create_var_env(key, value, data->secret_env);
	}
	return (OK);
}

static void	ft_export_value(char *key, char *value, t_data *data)
{
	char	*str;

	str = ft_is_key_in_env(key, data->env);
	if (str)
	{
		free(str);
		ft_change_value_in_env(key, value, data->env);
	}
	else
	{
		ft_create_var_env(key, value, data->env);
	}
	str = ft_is_key_in_env(key, data->secret_env);
	if (str)
	{
		free(str);
		ft_change_value_in_env(key, value, data->secret_env);
	}
	else
	{
		ft_create_var_env(key, value, data->secret_env);
	}
}

static void	ft_export_no_value(char *key, t_data *data)
{
	char	*str;

	str = ft_is_key_in_env(key, data->secret_env);
	if (str)
	{
		free(str);
		return ;
	}
	ft_create_var_env(key, "", data->secret_env);
}

static void	exec_export_argument(char *arg, t_data *data)
{
	char	*key;
	char	*value;

	if (ft_export_is_incorrect(arg) == -1)
	{
		g_exit_status = 1;
		ft_putstr_fd("minishell: export: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
		return ;
	}
	key = ft_dup_key(arg);
	value = ft_dup_value(arg);
	if (is_plus_equal(arg) == 1)
		ft_export_plus_equal(key, value, data);
	else if ((value == NULL || ft_strlen(value) == 0)
		&& arg_with_egal(arg) == 1)
		ft_export_no_value_with_egal(key, data);
	else if (value == NULL || ft_strlen(value) == 0)
		ft_export_no_value(key, data);
	else
		ft_export_value(key, value, data);
	free(key);
	free(value);
}

void	ft_export(char **args, t_data *data)
{
	int	i;

	i = 1;
	if (ft_len_tab(args) == 1)
	{
		ft_print_secret_env(data->secret_env);
		g_exit_status = 0;
		return ;
	}
	while (args[i])
	{
		exec_export_argument(args[i], data);
		i++;
	}
	if (g_exit_status == 1)
		return ;
	g_exit_status = 0;
}
