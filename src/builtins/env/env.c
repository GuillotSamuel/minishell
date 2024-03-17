/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:20:25 by emauduit          #+#    #+#             */
/*   Updated: 2024/03/17 17:24:04 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_print_env(t_env **env)
{
	t_env	*cur;

	cur = *env;
	while (cur)
	{
		printf("%s\n", cur->str);
		cur = cur->next;
	}
}

void	ft_print_secret_env(t_env **env)
{
	t_env	*cur;

	cur = *env;
	while (cur)
	{
		printf("declare -x ");
		printf("%s=", cur->key);
		printf("\"%s\"\n", cur->value);
		cur = cur->next;
	}
}

t_env	**dup_secret_env(t_env **env)
{
	t_env	**secret_env;
	t_env	*current;

	current = *env;
	secret_env = malloc(sizeof(t_env *));
	*secret_env = NULL;
	while (current)
	{
		if (ft_lst_env(current->str, secret_env) == ERROR)
			return (MALLOC_ERROR);
		current = current->next;
	}
	return (secret_env);
}

bool	ft_init_baby_env(t_env **env)
{
	char	*str;

	str = ft_strjoin("PWD=", getcwd(NULL, 0));
	if (str == NULL)
	{
		return (ERROR);
	}
	if (ft_lst_env(str, env) == 0)
	{
		free(str);
		return (ERROR);
	}
	if (ft_init_shlvl(env) == 0)
	{
		return (ERROR);
	}
	return (OK);
}

bool	ft_init_lst_env(const char **envp)
{
	int		len;
	t_env	**env;

	env = ft_singletone_env();
	len = ft_len_env(envp);
	if (len == 0)
	{
		if (ft_init_baby_env(env) == false)
		{
			ft_free_env_singletone(env);
			return (ERROR);
		}
	}
	len--;
	while (len >= 0)
	{
		ft_lst_env(envp[len], env);
		if ((*env)->str == NULL || (*env)->key == NULL)
		{
			ft_free_env_singletone(env);
			return (ERROR);
		}
		len--;
	}
	return (OK);
}
