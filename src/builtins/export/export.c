/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:29:14 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/13 11:03:10 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_export_plus_equal(char *key, char *value, t_data *data)
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

void	ft_change_value_in_env(char *key, char *value, t_env **env)
{
	t_env	*current;

	current = *env;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			free(current->str);
			current->str = ft_generate_env_str(key, value);
			return ;
		}
		current = current->next;
	}
}

void	ft_export_value(char *key, char *value, t_data *data)
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

void	ft_export_no_value(char *key, t_data *data)
{
	char	*str;

	str = ft_is_key_in_env(key, data->env);
	if (str)
	{
		free(str);
		return ;
	}
	ft_create_var_env(key, "", data->secret_env);
}


void	ft_export(char **args, t_data *data)
{
	char	*key;
	char	*value;
	int		i;

	i = 1;
	if (ft_len_tab(args) == 1)
	{
		ft_print_secret_env(data->secret_env);
		g_exit_status = 0;
		return ;
	}
	while (args[i])
	{
		if (ft_export_is_incorrect(args[i]) == -1)
		{
			g_exit_status = 1;
			ft_putstr_fd("minishell: export: ", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd(": not a valid identifier\n", 2);
			return ;
		}
		key = ft_dup_key(args[i]);
		value = ft_dup_value(args[i]);
		printf("value = %s\n", value);
		if (is_plus_equal(args[i]) == 1)
		{
			printf("JE RENTRE = %s\n", value);
			ft_export_plus_equal(key, value, data);
		}
		else if (value == NULL || ft_strlen(value) == 0)
		{
			ft_export_no_value(key, data);
		}
		else
			ft_export_value(key, value, data);
		free(key);
		free(value);
		i++;
	}
	g_exit_status = 0;
}
