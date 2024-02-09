/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:04:56 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/09 15:20:07 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/libft.h"
#include "struct.h"
#include "builtin.h"
#include "parsing.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

/* TESTS */
#include <stdio.h>

#define ERROR_MALLOC 1

/* -------------------------------------------------------------------------- */
/*                                    BUILTIN                                 */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                    INITIALISATION                          */
/* -------------------------------------------------------------------------- */

/* struct_init */
void		init_struct(t_data *data);

/* -------------------------------------------------------------------------- */
/*                                    PARSING                                 */
/* -------------------------------------------------------------------------- */

/* parsing */
void		parsing(char *line, t_data *data);

/* ---------------------------------- EXPAND -------------------------------- */


/* ---------------------------------- TOKEN --------------------------------- */

/* check_token_list */
int			check_token_list(t_cmd_line **cmd_list, t_data **data);

/* check_token_list_2 */
/* int         ft_array_cmp_consec(t_token **token_list_dup, t_data **data);
 */
/* line_ctrl */
int			line_ctrl(char *line, t_data *data);

/* line_lst */
t_cmd_line	*ft_stacknew_cmd(char *content);
void		ft_stackaddback_cmd(t_cmd_line **cmd_lst, t_cmd_line *new);
int			create_cmd(char *line, t_cmd_line **cmd_list, t_data **data);

/* token */
int			token(char *line, t_data *data);

/* type */
void		put_type(t_cmd_line **cmd_list, t_data **data);

/* utils_line */
int			cut_cmd(char *str , t_data *data);

/* utils_token_ft.c */
int 		cut_token(char *str, t_data *data);
void		rm_node(t_token **token_list_dup, t_token **token_list_dup_prev);

/* utils_token_lst.c */
void		create_token(t_cmd_line **cmd_list, t_data **data);
void		ft_stackaddback_token(t_token **lst, t_token *new);
t_token		*ft_stacknew_token(char *content);

/* utils_token */
int			ft_charcmp_array(char c, const char **array);
int			ft_strcmp_space(const char *s1, const char *s2);
int			ft_strcmp_array_space(const char *str, const char **array);
int			end_ctrl(char *str);
char		*ft_remove_nchar_fromstr(char *cmd_line, int n);

/* -------------------------------------------------------------------------- */
/*                                    UTILS                                   */
/* -------------------------------------------------------------------------- */

/* exit_error */
void		exit_error(t_data *data);
void	    two_pipes_error(t_data *data);

/* free_all */
void	    clear_lists(t_data *data);
void		free_all(t_data *data);

#endif