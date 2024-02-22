/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:29:14 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/22 17:09:26 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/* extern int	g_exit_status;

void	ft_export(char *key, char *value, t_data **data)
{
	t_data	*data_tmp;

	data_tmp = (*data)->env;
	while (data_tmp)
	{
		if (ft_strcmp(data_tmp->key, key) == SUCCESS)
		{
			free(data_tmp->value);
			data_tmp->value = ft_strdup(value);
			(*data)->env = data_tmp;
			return;
		}
		data_tmp = data_tmp->next;
	}
	t_env *new_env = malloc(sizeof(t_env));
	if (!new_env)
	{
		g_exit_status = 1;
		free_all(data);
		exit(g_exit_status);
	}
	data_tmp = data_tmp;
	new_env->key = ft_strdup(key);
	new_env->value = ft_strdup(value);
	new_env->next = data_tmp;
	(*data)->env = new_env;
	g_exit_status = 0;
}

static void	ft_export_value(char *key, char *value, t_data **data)
{
	
}

static void	ft_export_no_value(char *key, t_data **data)
{
	t_env	*env_tmp;

	env_tmp = (*data)->dup_secret_env;
	while (env_tmp)
	{
		if (ft_strcmp(env_tmp->key, key) == SUCCESS)
		{
			free(env_tmp->value);
			env_tmp->value = NULL;
			return ;
		}
		env_tmp = env_tmp->next;
	}
	t_env *new_env = malloc(sizeof(t_env));
	if (!new_env)
		exit_error(*data);
	new_env->key = ft_strdup(key);
	new_env->value = NULL;
	new_env->next = (*data)->dup_secret_env;
	(*data)->dup_secret_env = new_env;
	g_exit_status = 0;
}

void	ft_export(char *key, char *value, t_data **data)
{
	if (value == NULL)
		ft_export_no_value(key, data);
	else
		ft_export_value(key, value, data);
	g_exit_status = 0;
}
 */