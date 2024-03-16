/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:57:57 by azbk              #+#    #+#             */
/*   Updated: 2024/03/15 14:00:56 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

/* -------------------------------------------------------------------------- */
/*                                    CHECK_BUILTIN                             */
/* -------------------------------------------------------------------------- */

/* check_builtin */
int		check_builtin(char *arg);
int		exec_builtin(t_cmd_line *cmd, t_data *data);
int		exec_builtin_one_cmd(t_cmd_line *cmd, t_data *data);

/* -------------------------------------------------------------------------- */
/*                                      CMD_EXIST                             */
/* -------------------------------------------------------------------------- */

/* exist.c */
char	*ft_cmd_exist(char *cmd);
char	*ft_get_env(char *key, t_env *env);

/* -------------------------------------------------------------------------- */
/*                                      CORE_EXEC                             */
/* -------------------------------------------------------------------------- */

/* free_utils.c */
void	free_pipes_fd(t_data *data);

/* init_exec.c */
int init_exec(t_data *data);
int start_exec(t_data *data);
int	cmd_nb(t_cmd_line *cmd);
void forking_exec(t_data *data);

/* init_exec.c */
int		init_exec(t_data *data);
int		start_exec(t_data *data);
void	redirect_io(t_cmd_line *cmd_list);


/* execve_exec.c */
int	ft_execve_exec(char *path, t_cmd_line *cmd_list_dup, t_data *data);

/* -------------------------------------------------------------------------- */
/*                                      HERE_DOC                              */
/* -------------------------------------------------------------------------- */

/* create_random */
int		ft_random(void);
char	*create_random_name(void);

/* heredoc */
int		start_here_doc(t_redir *redir, t_token *token_list);

/* -------------------------------------------------------------------------- */
/*                                    REDIRECTION                             */
/* -------------------------------------------------------------------------- */
/* redirection */
int		file_in(t_redir *redir, t_token *token_list);
int		write_or_overwrite_file(t_redir *redir, t_token *token_list,
			enum_type type);
int		open_all_redirections(t_cmd_line *cmd);

#endif