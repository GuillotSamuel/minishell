/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:28:19 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/13 11:07:43 by azbk             ###   ########.fr       */
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

static void	ft_unset_env(char *key)
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

static void	ft_unset_secret_env(char *key, t_env **secret_env)
{
	t_env	*current;
	t_env	*prev;

	current = *secret_env;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			remove_node(secret_env, prev, current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void ft_unset(t_cmd_line *cmd, t_data *data)
{
	int i;

	i = 1;
	if (cmd->args[i] == NULL)
	{
		return ;
	}
	while (cmd->args[i])
	{
		ft_unset_env(cmd->args[i]);
		ft_unset_secret_env(cmd->args[i], data->secret_env);
		i++;
	}
}
