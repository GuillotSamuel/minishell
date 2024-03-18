/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:46:45 by azbk              #+#    #+#             */
/*   Updated: 2024/03/18 21:45:42 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

char	*ft_get_env(char *key, t_env *env)
{
	while (env && env->key)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

static char	*join_path(char *path, char *cmd)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(path, "/");
	if (tmp == NULL)
		return (NULL);
	tmp2 = ft_strjoin(tmp, cmd);
	free(tmp);
	return (tmp2);
}

static char	*ft_access(char *path)
{
	if (access(path, F_OK) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_exit_status = 127;
		return (NULL);
	}
	if (access(path, X_OK) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		g_exit_status = 126;
		return (NULL);
	}
	return (path);
}

static char	*check_cmd(char **tab, char *cmd)
{
	size_t	i;
	char	*tmp;

	i = -1;
	while (tab[++i])
	{
		tmp = join_path(tab[i], cmd);
		if (tmp == NULL)
			return (VAR_NOT_FOUND);
		if (access(tmp, F_OK) == 0)
		{
			if (access(tmp, X_OK) == 0)
			{
				return (tmp);
			}
			else
			{
				free(tmp);
				return (VAR_NOT_FOUND);
			}
		}
		free(tmp);
	}
	return (VAR_NOT_FOUND);
}

char	*ft_cmd_exist(char *cmd)
{
	char	*var_path;
	t_env	**env;
	char	**tab;
	char	*path;

	if (cmd && (cmd[0] == '.' || cmd[0] == '/'))
		return (ft_access(cmd));
	env = ft_singletone_env();
	var_path = ft_get_env("PATH", *env);
	if (var_path == NULL)
		return (MALLOC_ERROR);
	tab = ft_split(var_path, ':');
	if (tab == NULL)
		return (MALLOC_ERROR);
	path = check_cmd(tab, cmd);
	if (path == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		g_exit_status = 127;
	}
	ft_free_array(tab);
	return (path);
}
