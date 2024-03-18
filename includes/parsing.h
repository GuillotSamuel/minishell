/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:36:51 by emauduit          #+#    #+#             */
/*   Updated: 2024/03/18 12:33:08 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* -------------------------------------------------------------------------- */
/*                                    PARSING                                 */
/* -------------------------------------------------------------------------- */

/* parsing */
int			parsing(char *line, t_data *data);

/* -------------------------------------------------------------------------- */
/*                                    EXPAND                                  */
/* -------------------------------------------------------------------------- */

int		check_args_array_after_expands(t_cmd_line *cmd, t_data *data);
int			args_counter(char **args);
bool		expand_all_tokens(t_data *data);
char		*expand_smpl_quotes(const char *line, char *str_expand, int *i);
char		*expand_no_quote(t_token **tok, const char *line, char *str_expand,
				int *i);
char		*expand_dbl_quotes(const char *line, char *str_expand, int *i);
char		*init_exp_with_dollar(const char *line, char *str_expand, int *i);
char		*exp_without_dollar(const char *line, char *str_expand, int *i);
char		*exp_with_dollar(const char *line, int *i);
char		*exp_no_quote_no_dol(const char *line, char *str_expand, int *i);
bool		prepare_execution(t_data *data);

char		*init_no_quote_with_dollar(t_token **token, const char *line,
				char *str_expand, int *i);

/* -------------------------------------------------------------------------- */
/*                                  UTILS                                     */
/* -------------------------------------------------------------------------- */
size_t		find_len_var(const char *line);
char		*get_value_env(const char *variable);

/* -------------------------------------------------------------------------- */
/*                                  DEL QUOTES                                */
/* -------------------------------------------------------------------------- */

void		delete_quote(char *new_str, char *line, int i, int j);
bool		init_delete_quote(t_token *lst_token, char *line);

// FREE A VOIR SI ON DEL
void		print_cmd(t_data *data);
void		ft_free_data(t_data *data);
void		ft_free_commands(t_cmd_line *command);
void		ft_free_cmd(t_cmd_line *cmd);
void		ft_free_array(char **tab);
void		ft_free_tokens(t_token *tokens);

/* ---------------------------------- TOKEN --------------------------------- */

/* token */
int			token(char *line, t_data *data);

/* command_assign_1 */
int			create_cmd_1(char *line, t_cmd_line **cmd_list, t_data **data);

/* command_assign_utils */
void		ft_stackaddback_cmd(t_cmd_line **line, t_cmd_line *new);
t_cmd_line	*ft_stacknew_cmd(char *content);
int			cut_cmd(char *str);

/* ctrl_consecutive_pipes */
int			consecutive_pipes_ctrl(char *line);

/* line_ctrl_1 */
int			line_ctrl(char *line);

/* line_ctrl_2 */
int			ft_space_ctrl_1(char *line, char cmp_str, char cmp_str2);
int			ft_strcmp_array_space_3(char *l, const char **ca, char *cs);
int			forbiden_consecutive(char *line);
int			forbiden_char(char *line);

/* line_ctrl_1inferior */
int			control_i1(char *line);
int			control_i2(char *line);

/* line_ctrl_1superior */
int			control_s1(char *line);
int			control_s2(char *line);

/* line_ctrl_2inferior */
int			control_ii1(char *line);
int			control_ii2(char *line);

/* line_ctrl_2superior */
int			control_ss1(char *line);
int			control_ss2(char *line);

/* line_ctrl_utils_1 */
int			ft_strcmp_array_space_2(char *l, const char **cmp_arr,
				char *cmp_str);

/* line_ctrl_utils_2 */
void		ft_ignore_quotes(char *l, int *i);

/* token_assign_1 */
void		create_token_1(t_cmd_line **cmd_list, t_data **data);

/* token_utils_1 */
char		*ft_remove_nchar_from_str_2(char *cmd_line, int n);
char		*ft_remove_nchar_from_str(char *cmd_line, int n);
int			ft_strcmp_array_space(const char *str, const char **array);
int			ft_strcmp_space(const char *s1, const char *s2);
int			ft_charcmp_array(char c, const char **array);

/* token_utils_2 */
int			end_ctrl_1(char *str);

/* token_utils_3 */
int			cut_token_1(char *str, t_data *data);
void		rm_node(t_token **token_list_dup, t_token **token_list_dup_prev);

/* token_utils_4 */
t_token		*ft_stacknew_token(char *content);
void		ft_stackaddback_token(t_token **lst, t_token *new);

/* token_list_control_1 */
int			check_token_list(t_cmd_line **cmd_list, t_data **data);
void		empty_token_ctrl(char *token, t_token **token_list_dup,
				t_token **token_list_dup_prev);

/* type_assign_1 */
void		put_type_1(t_cmd_line **cmd_list);

/* type_assign_2 */
void		word_chevron(char *prev_token, t_token *token_list);
void		chevron(char *token, t_token *token_list);

#endif