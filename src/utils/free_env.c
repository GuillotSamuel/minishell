/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:44:01 by emauduit          #+#    #+#             */
/*   Updated: 2024/03/14 17:25:00 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_env_singletone(t_env **env)
{
	t_env	*cur;
	t_env	*prev;

	cur = *env;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		free(prev->str);
		free(prev->key);
		free(prev->value);
		free(prev);
	}
}

static void	ft_free_secret_env(t_env **secret_env)
{
	t_env	*cur;
	t_env	*prev;

	cur = *secret_env;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		free(prev->str);
		free(prev->key);
		free(prev->value);
		free(prev);
	}
	free(secret_env);
}

void	ft_free_both_env(t_data *data)
{
	t_env	**env;

	env = ft_singletone_env();
	ft_free_env_singletone(env);
	ft_free_secret_env(data->secret_env);
}
