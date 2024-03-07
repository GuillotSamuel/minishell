/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:29:14 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/07 13:21:09 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../includes/minishell.h"

static char	*ft_generate_env_str(char *key, char *value)
{
	char	*env_str;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	env_str = malloc(sizeof(char) * (ft_strlen(key) + ft_strlen(value) + 2));
	while (key[j])
	{
		env_str[i] = key[j];
		i++;
		j++;
	}
	env_str[i] = '=';
	i++;
	while (value[j])
	{
		env_str[i] = value[j];
		i++;
		j++;
	}
	env_str[i] = '\0';
	return (env_str);
}

static void	ft_export_value_2(char *key, char *value, t_data **data)
{
	t_env	*secret_env_tmp;
	t_env	*new_secret_env;

	secret_env_tmp = (*data)->env;
	while (secret_env_tmp)
	{
		if (ft_strcmp(secret_env_tmp->key, key) == SUCCESS)
		{
			free(secret_env_tmp->value);
			secret_env_tmp->value = NULL;
			return ;
		}
		secret_env_tmp = secret_env_tmp->next;
	}
	new_secret_env = malloc(sizeof(t_env));
	if (!new_secret_env)
		exit_error(*data);
	new_secret_env->key = ft_strdup(key);
	new_secret_env->value = value;
	new_secret_env->next = (*data)->env;
	(*data)->env = new_secret_env;
}

static void	ft_export_value_1(char *key, char *value, t_data **data)
{
	t_env	*env_tmp;
	t_env	*new_env;

	ft_export_value_2(key, value, data);
	env_tmp = (*data)->env;
	while (env_tmp)
	{
		if (ft_strcmp(env_tmp->key, key) == SUCCESS)
		{
			free(env_tmp->value);
			env_tmp->value = value;
			return ;
		}
		env_tmp = env_tmp->next;
	}
	new_env = malloc(sizeof(t_env));
	if (!new_env)
		exit_error(*data);
	new_env->key = ft_strdup(key);
	new_env->value = value;
	new_env->next = (*data)->env;
	(*data)->env = new_env;
	g_exit_status = 0;
}

static void	ft_export_no_value(char *key, t_data **data)
{
	t_env	*secret_env_tmp;
	t_env	*new_secret_env;

	secret_env_tmp = (*data)->env;
	while (secret_env_tmp)
	{
		if (ft_strcmp(secret_env_tmp->key, key) == SUCCESS)
		{
			free(secret_env_tmp->value);
			secret_env_tmp->value = NULL;
			return ;
		}
		secret_env_tmp = secret_env_tmp->next;
	}
	new_secret_env = malloc(sizeof(t_env));
	if (!new_secret_env)
		exit_error(*data);
	new_secret_env->key = ft_strdup(key);
	new_secret_env->value = NULL;
	new_secret_env->next = (*data)->env;
	(*data)->env = new_secret_env;
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