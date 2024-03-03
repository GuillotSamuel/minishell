/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:28:19 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/03 16:55:11 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	remove_node(t_env **env, t_env *prev, t_env *current)
{
	if (!prev)
		*env = current->next;
	else
		prev->next = current->next;
	free(current->key);
	free(current->value);
	free(current->str);
	free(current);
}

void	ft_unset(char *key)
{
	t_env	**env;
	t_env	*current;
	t_env	*prev;

	env = ft_singletone_env();
	current = *env;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			remove_node(env, prev, current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
