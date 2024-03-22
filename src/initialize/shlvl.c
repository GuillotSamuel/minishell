/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:29:54 by emauduit          #+#    #+#             */
/*   Updated: 2024/03/19 15:15:34 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_update_shlvl(char *line, t_env **env_list, int level)
{
	t_env	*cur;

	cur = *env_list;
	if (level > 1)
	{
		while (cur)
		{
			if (ft_strncmp("SHLVL", cur->key, 5) == 0)
			{
				free(cur->value);
				free(cur->str);
				cur->value = ft_itoa(level);
				if (cur->value == NULL)
					return (ERROR);
				cur->str = ft_strdup(line);
			}
			cur = cur->next;
		}
	}
	else
	{
		if (ft_lst_env(line, env_list) == 0)
			return (ERROR);
	}
	return (OK);
}

char	*find_env(char *line, t_env *env_list)
{
	char	*new_str;
	t_env	*cur;

	cur = env_list;
	while (cur)
	{
		if (ft_strncmp(line, cur->key, 5) == 0)
		{
			new_str = ft_strdup(cur->value);
			return (new_str);
		}
		cur = cur->next;
	}
	return (NULL);
}

static bool	update_shlvl_env(t_env **env_list, int level)
{
	char	*level_str;
	char	*new_str;

	level_str = ft_itoa(level);
	if (level_str == NULL)
		return (ERROR);
	new_str = ft_strjoin("SHLVL=", level_str);
	free(level_str);
	if (new_str == NULL)
		return (ERROR);
	if (ft_update_shlvl(new_str, env_list, level) == 0)
	{
		free(new_str);
		return (ERROR);
	}
	free(new_str);
	return (OK);
}

bool	ft_init_shlvl(t_env **env_list)
{
	char	*shlvl_str;
	int		level;

	shlvl_str = find_env("SHLVL", *env_list);
	if (shlvl_str == NULL)
	{
		level = 1;
	}
	else
	{
		level = ft_atoi(shlvl_str) + 1;
		free(shlvl_str);
	}
	return (update_shlvl_env(env_list, level));
}
