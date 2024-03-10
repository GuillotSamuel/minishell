/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:50:00 by azbk              #+#    #+#             */
/*   Updated: 2024/03/10 18:02:16 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../includes/minishell.h"

extern int	g_exit_status;

int	ft_pwd_exist(t_env **env, char *key, char *pwd)
{
	t_env	*current;

	current = *env;
	while (current)
	{
		if (ft_strcmp(key, current->key) == 0)
		{
			free(current->value);
			current->value = ft_strdup(pwd);
			return (OK);
		}
		else
			current = current->next;
	}
	return (FAIL);
}
int	ft_pwd_dont_exist(t_env **env, char *key, char *pwd)
{
	char	*add_egal;
	char	*str;

	add_egal = ft_strjoin(key, "=");
	if (add_egal == NULL)
		return (FAIL);
	str = ft_strjoin(add_egal, pwd);
	free(add_egal);
	if (str == NULL)
		return (FAIL);
	if (ft_lst_env(str, env) == ERROR)
	{
		free(str);
		return (FAIL);
	}
	free(str);
	return (OK);
}

size_t	ft_len_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

int	check_oldpwd(t_env **env, char *pwd)
{
	if (ft_pwd_exist(env, "OLDPWD", pwd) == 1)
	{
		return (OK);
	}
	else
	{
		if (ft_pwd_dont_exist(env, "OLDPWD", pwd) == -1)
			return (FAIL);
	}
	return (OK);
}

int	ft_change_pwd(t_env **env)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		pwd = find_key_in_env("OLDPWD");
	}
	if (ft_pwd_exist(env, "PWD", pwd) == 1)
	{
		free(pwd);
		return (OK);
	}
	else
	{
		if (ft_pwd_dont_exist(env, "PWD", pwd) == -1)
		{
			free(pwd);
			return (FAIL);
		}
	}
	free(pwd);
	return (OK);
} */
