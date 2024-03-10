/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:46:45 by azbk              #+#    #+#             */
/*   Updated: 2024/03/10 18:09:17 by sguillot         ###   ########.fr       */
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

static char *trim_cmd(char *cmd)
{
    char *trimmed_cmd;
    int     cmd_len;
    int     i;
    
    i = 0;
    while (cmd[i] == ' ')
        i++;
    while (cmd[i] != ' ' && cmd[i] != '\0')
    {
        cmd_len++;
        i++;
    }
    trimmed_cmd = malloc(sizeof(char) * (cmd_len + 1));
    if (trimmed_cmd == NULL)
        return (NULL);
    i = 0;
    while (cmd[i] == ' ')
        i++;
    while (cmd[i] != ' ' && cmd[i] != '\0')
    {
        trimmed_cmd[i] = cmd[i];
        i++;
    }
    trimmed_cmd[i] = '\0';
    return (trimmed_cmd);
}

static char* join_path(char *path, char *cmd)
{
    char *tmp;
    char *tmp2;
    char *trimmed_path;
    char *trimmed_cmd;

    trimmed_path = ft_strtrim(path, " ");
    trimmed_cmd = trim_cmd(cmd);
    tmp = ft_strjoin(trimmed_path, "/");
    if (tmp == NULL)
        return (NULL);
    tmp2 = ft_strjoin(tmp, trimmed_cmd);
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

