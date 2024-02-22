/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:20:25 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/22 17:57:33 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

size_t ft_len_env(const char **envp)
{
    size_t i;
    
    i = 0;
    if (!envp)
        return (0);
    while (envp[i])
        i++;
    return (i);
}

/* static char *ft_dup_key(const char *line)
{
    int i;
    char *key;
    
    i = 0;
    while (line && line[i] && line[i] != '=')
    {
        i++;
    }
    if (i == 0)
        return (VAR_EMPTY);
    key = malloc(sizeof(char) * (i + 1));
    if (key == NULL)
        return (MALLOC_ERROR);
    ft_strncpy(key, line, i);
    return (key);
}

static char *ft_dup_value(const char *line)
{
    int i;
    char *value;

    i = 0;
    while(line && line[i] && line[i] != '=')
        i++;
    if (line[i] == '=')
        i++;
    value = ft_strdup(&line[i]);
    if (value == NULL)
        return (MALLOC_ERROR);
    return (value);
} */


