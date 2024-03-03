/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:14:10 by emauduit          #+#    #+#             */
/*   Updated: 2024/03/03 22:30:24 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

static int	is_in_env(t_env **env, char *key, char *pwd)
{
	t_env	*current;

	current = *env;
	while (current)
	{
		if (ft_strcmp(key, current->key) == 0)
		{
			free(current->value);
			current->value = ft_strdup(pwd);
			free(pwd);
			return (OK);
		}
		else
			current = current->next;
	}
	return (FAIL);
}

static int	ft_add_oldpwd(t_env **env, char *key, char *pwd)
{
	char	*add_egal;
	char	*str;

	add_egal = ft_strjoin(key, "=");
	if (add_egal == NULL)
		return (FAIL);
	str = ft_strjoin(add_egal, pwd);
	free(pwd);
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

static void	check_oldpwd(t_env **env)
{
	t_env	*current;
	char	*pwd;

	current = *env;
	pwd = getcwd(NULL, 0);
	if (is_in_env(env, "OLDPWD", pwd) == 1)
	{
		return (OK);
	}
	else
	{
		if (ft_add_oldpwd(env, "OLDPWD", pwd) == -1)
			return (FAIL);
	}
	return (OK);
}

static int	ft_exec_cd(char **args, char *path)
{
	if (args[1] == NULL || args[1][0] == '~')
	{
		path = ft_get_env("HOME", *env);
		if (path == NULL)
		{
			ft_putstr_fd("Minishell: cd: HOME not set\n", 2);
			g_exit_status = 1;
			return (FAIL);
		}
	}
	else if (ft_strcmp(args[1], "..") == 0)
		path = ft_strdup("..");
	else
		path = ft_strdup(args[1]);
	if (chdir(path) == -1)
	{
		free(path);
		ft_putstr_fd("Minishell: cd: %s: No such file or directory");
		g_exit_status = 1;
		return (FAIL);
	}
	free(path);
	return (OK);
}

int	ft_cd(char **args)
{
	char	*path;
	t_env	**env;

	env = ft_singletone_env();
	check_oldpwd(env);
	if (ft_strlen(args[2] > 0))
	{
		ft_putstr_fd("Minishell: cd: too many arguments", 2);
		g_exit_status = 1;
		return (FAIL);
	}
	if (ft_exec_cd(args, path) == -1)
		return (FAIL);
	return (OK);
}
