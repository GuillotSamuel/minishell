/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:23:31 by azbk              #+#    #+#             */
/*   Updated: 2024/03/13 11:01:11 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_generate_env_str(char *key, char *value)
{
	char	*str;
	char *tmp;

	str = ft_strdup(key);
	if (str == NULL)
		return (NULL);
	tmp = ft_strjoin(str, "=");
	free(str);
	if (tmp == NULL)
		return (NULL);
	str = ft_strjoin(tmp, value);
	free(tmp);
	return (str);
}

char	*ft_is_key_in_env(char *key, t_env **env)
{
	t_env	*current;

	current = *env;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (ft_strdup(current->str));
		current = current->next;
	}
	return (NULL);
}

int	ft_create_var_env(char *key, char *value, t_env **env)
{
	t_env	*current;

	current = *env;
	while (current->next)
	{
		current = current->next;
	}
	current->next = malloc(sizeof(t_env));
	if (current->next == NULL)
		return (FAIL);
	current->next->str = ft_generate_env_str(key, value);
	current->next->key = ft_strdup(key);
	current->next->value = ft_strdup(value);
	current->next->next = NULL;
	return (OK);
}

int	ft_add_value_in_env(char *key, char *value, char *str, t_env **env)
{
	t_env	*current;
	char	*new_str;

	new_str = ft_strjoin(str, value);
	if (new_str == NULL)
		return (FAIL);
	current = *env;
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->str);
			current->str = new_str;
			free(current->value);
			current->value = ft_dup_value(new_str);
			if (current->value == NULL)
				return (FAIL);
			return (OK);
		}
		current = current->next;
	}
	return (FAIL);
}
