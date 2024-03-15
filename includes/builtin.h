/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:25:59 by azbk              #+#    #+#             */
/*   Updated: 2024/03/15 19:08:04 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

/* -------------------------------------------------------------------------- */
/*                                    PWD                                     */
/* -------------------------------------------------------------------------- */

/* pwd */
char	*find_key_in_env(char *key);
void	ft_pwd(void);

/* -------------------------------------------------------------------------- */
/*                                    CD                                      */
/* -------------------------------------------------------------------------- */

/* cd */
int		ft_cd(char **args, t_data *data);

/* update_pwd */
int		ft_pwd_exist(t_env **env, char *key, char *pwd);
int		ft_change_pwd(t_env **env);
int		check_oldpwd(t_env **env, char *pwd);
size_t	ft_len_tab(char **tab);

/* -------------------------------------------------------------------------- */
/*                                    ECHO                                    */
/* -------------------------------------------------------------------------- */

/* echo */
void	ft_echo(char **args);

/* -------------------------------------------------------------------------- */
/*                                    ENV                                     */
/* -------------------------------------------------------------------------- */

/* env */
t_env	**dup_secret_env(t_env **env);
bool	ft_init_baby_env(t_env **env);
bool	ft_init_lst_env(const char **envp);
void	ft_print_secret_env(t_env **env);

/* lst_env */
bool	ft_lst_env(const char *line, t_env **env);
size_t	ft_len_env(const char **envp);

/* -------------------------------------------------------------------------- */
/*                                    EXIT                                    */
/* -------------------------------------------------------------------------- */

/* exit */
void	ft_exit(char **args, t_data *data);

/* exit_utils */
int		ft_is_positive_llong(char *str);
void	exit_one_neg_num(t_data *data);
int	ft_is_negative_llong(char *str);

/* -------------------------------------------------------------------------- */
/*                                    EXPORT                                  */
/* -------------------------------------------------------------------------- */

/* check_export.c */
int		is_plus_equal(char *str);
int		ft_export_is_incorrect(char *str);

/* export_tools */
char	*ft_is_key_in_env(char *key, t_env **env);
char	*ft_generate_env_str(char *key, char *value);
int		ft_create_var_env(char *key, char *value, t_env **env);
int		ft_add_value_in_env(char *key, char *value, char *str, t_env **env);

/* export */
void	ft_change_value_in_env(char *key, char *value, t_env **env);
void	ft_export(char **args, t_data *data);

/* -------------------------------------------------------------------------- */
/*                                    UNSET                                   */
/* -------------------------------------------------------------------------- */

void	ft_unset(t_cmd_line *cmd, t_data *data);

#endif