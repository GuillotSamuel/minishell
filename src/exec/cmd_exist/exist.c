/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:46:45 by azbk              #+#    #+#             */
/*   Updated: 2024/03/06 17:48:44 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char *ft_get_env(char *key, t_env *env)
{
    while (env && env->key)
    {
        if (ft_strcmp(env->key, key) == 0)
            return (env->value);
        env = env->next;
    }
    return (NULL);
}

static char* join_path(char *path, char *cmd)
{
    char *tmp;
    char *tmp2;

    tmp = ft_strjoin(path, "/");
    if (tmp == NULL)
        return (NULL);
    tmp2 = ft_strjoin(tmp, cmd);
    free(tmp);
    return (tmp2);
}

static int check_cmd(char **tab, char *cmd)
{
    size_t i;
    char *tmp;
    
    i = -1;
    while (tab[++i])
    {
        tmp = join_path(tab[i], cmd);
        if (tmp == NULL)
            return (FAIL);
        if (access(tmp, F_OK) == 0)
        {
            if(access(tmp, X_OK) == 0)
            {
                free(tmp);
                return (OK);
            }
            else
            {
                free(tmp);
                return (FAIL);                     
            }
        }
        free(tmp);
    }
    return (FAIL);
}


int ft_cmd_exist(char *cmd)
{
    char *path;    
    t_env **env;
    char **tab;

    env = ft_singletone_env();
    path = ft_get_env("PATH", *env);
    if (path == NULL)
        return (FAIL);
    tab = ft_split(path, ':');
    if (tab == NULL)
        return (FAIL);
    if (check_cmd(tab, cmd) == OK)
    {
        ft_free_array(tab);
        return (OK);
    }
    else
    {
        ft_free_array(tab);
        return (FAIL);
    }
}

