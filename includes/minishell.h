/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:04:56 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/22 18:15:54 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* -------------------------------------------------------------------------- */
/*                                    INCLUDES                                */
/* -------------------------------------------------------------------------- */

# include "../libft/libft.h"
# include "struct.h"
# include "builtin.h"
# include "parsing.h"
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>

/* TESTS */
# include <stdio.h>

/* -------------------------------------------------------------------------- */
/*                                    DEFINE                                  */
/* -------------------------------------------------------------------------- */

# define SUCCESS 0
# define ERROR_G -1
# define ERROR_SYNTAX -2
# define ERROR_MALLOC -3

# define MALLOC_ERROR NULL
# define VAR_EMPTY NULL
# define ERROR false
# define OK true

/* -------------------------------------------------------------------------- */
/*                                    INITIALISATION                          */
/* -------------------------------------------------------------------------- */

/* lst_env */
bool	ft_lst_env(const char *line, t_env **env);
bool	ft_init_baby_env(t_env **env);
bool	ft_init_lst_env(const char **envp);

/* shlvl */
bool	ft_init_shlvl(t_env **env_list);
char *find_env(char *line, t_env *env_list);
bool    ft_update_shlvl(char *line, t_env **env_list, int level);

/* -------------------------------------------------------------------------- */
/*                                    UTILS                                   */
/* -------------------------------------------------------------------------- */

/* exit_error */
void	exit_error(t_data *data);

/* free_all_1 */
void	clear_lists(t_data *data);
void	free_all(t_data *data);

/* free_env */
void ft_free_both_env(t_data *data);
void	ft_free_env_singletone(t_env **env);

/* singletone */
t_env	**ft_singletone_env(void);

#endif