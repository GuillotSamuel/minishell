/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:57:57 by azbk              #+#    #+#             */
/*   Updated: 2024/03/08 16:18:44 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

/* -------------------------------------------------------------------------- */
/*                                      CMD_EXIST                             */
/* -------------------------------------------------------------------------- */

int		ft_cmd_exist(char *cmd);
char	*ft_get_env(char *key, t_env *env);

/* -------------------------------------------------------------------------- */
/*                                      HERE_DOC                              */
/* -------------------------------------------------------------------------- */

/* create_random */
int ft_random(void);
char *create_random_name(void);

/* heredoc */
int start_here_doc(t_redir *redir, t_token *token_list);

/* -------------------------------------------------------------------------- */
/*                                    REDIRECTION                             */
/* -------------------------------------------------------------------------- */
/* redirection */
int file_in(t_redir *redir, t_token *token_list);
int write_or_overwrite_file(t_redir *redir, t_token *token_list, enum_type type);
int open_all_redirections(t_cmd_line *cmd);


#endif