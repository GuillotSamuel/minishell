/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:29:14 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/22 12:02:20 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

/* void	ft_export(char *key, char *value, t_data **data)
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
} */
