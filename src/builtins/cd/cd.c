/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:14:10 by emauduit          #+#    #+#             */
/*   Updated: 2024/03/17 18:05:12 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

static char	*find_path_in_env(t_env **env, char **args, char *path)
{
	if (args[0] == NULL || args[0][0] == '~')
	{
		path = ft_strdup(ft_get_env("HOME", *env));
		if (path == NULL)
		{
			ft_putstr_fd("Minishell: cd: HOME not set\n", 2);
			g_exit_status = 1;
			return (NULL);
		}
	}
	else if (args[0][0] == '-')
	{
		path = ft_strdup(ft_get_env("OLDPWD", *env));
		if (path == NULL)
		{
			ft_putstr_fd("Minishell: cd: OLDPWD not set\n", 2);
			g_exit_status = 1;
			return (NULL);
		}
		else
			ft_printf("%s\n", path);
	}
	return (path);
}

static char	*prepare_path(char **args, t_env **env)
{
	char	*path;

	path = NULL;
	if (args[0] == NULL || args[0][0] == '~' || args[0][0] == '-')
	{
		return (find_path_in_env(env, args, path));
	}
	else
		path = ft_strdup(args[0]);
	return (path);
}

static int	execute_cd_and_update_env(char *path, t_env **env,
		t_env **secret_env)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		pwd = find_key_in_env("PWD");
	if (pwd == NULL)
		return (FAIL);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("Minishell: cd: %s: No such file or directory\n", 2);
		g_exit_status = 1;
		free(pwd);
		free(path);
		return (FAIL);
	}
	check_oldpwd(env, pwd);
	check_oldpwd(secret_env, pwd);
	free(path);
	free(pwd);
	return (OK);
}

static int	ft_exec_cd(char **args, t_env **env, t_env **secret_env)
{
	char	*path;

	path = prepare_path(args, env);
	if (path == NULL)
		return (FAIL);
	return (execute_cd_and_update_env(path, env, secret_env));
}

int	ft_cd(char **args, t_data *data)
{
	t_env	**env;
	t_env	**secret_env;

	env = data->env;
	secret_env = data->secret_env;
	if (ft_len_tab(args) > 1)
	{
		ft_putstr_fd("Minishell: cd: too many arguments", 2);
		g_exit_status = 1;
		return (FAIL);
	}
	if (ft_exec_cd(args, env, secret_env) == -1)
		return (FAIL);
	if (ft_change_pwd(env) == -1)
		return (FAIL);
	if (ft_change_pwd(secret_env) == -1)
		return (FAIL);
	g_exit_status = 0;
	return (OK);
}
