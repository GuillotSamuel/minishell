/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:57:57 by azbk              #+#    #+#             */
/*   Updated: 2024/03/13 18:06:26 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H


/* -------------------------------------------------------------------------- */
/*                                    CHECK_BUILTIN                             */
/* -------------------------------------------------------------------------- */

/* check_builtin */
int    check_builtin(char *arg);
int exec_builtin(t_cmd_line *cmd, t_data *data);

/* -------------------------------------------------------------------------- */
/*                                      CMD_EXIST                             */
/* -------------------------------------------------------------------------- */

/* exist.c */
char		*ft_cmd_exist(char *cmd);
char	*ft_get_env(char *key, t_env *env);

/* -------------------------------------------------------------------------- */
/*                                      CORE_EXEC                             */
/* -------------------------------------------------------------------------- */

/* free_utils.c */
void	free_pipes_fd(int **pipes_fd, int nb_pipes);

/* init.c */
int alloc_pipes(t_cmd_line *cmd, int **pipes_fd, int i);
int init_pipes(t_cmd_line *cmd, size_t nb_cmd);
int init_exec(t_data *data);
int start_exec(t_data *data);


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