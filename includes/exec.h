/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:57:57 by azbk              #+#    #+#             */
/*   Updated: 2024/03/07 14:32:07 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

/* -------------------------------------------------------------------------- */
/*                                      exec                                  */
/* -------------------------------------------------------------------------- */

/* exec_1 */
void	exec_commands(t_cmd_line *cmd_list_dup, t_data *data);

/* exec_2 */
void	exec_builtins(t_cmd_line *cmd, t_data *data);
void	exec_externals(t_cmd_line *cmd, t_data *data);
void	convert_env_to_array(t_env **env, t_data *data);

/* -------------------------------------------------------------------------- */
/*                                      cmd_exist                             */
/* -------------------------------------------------------------------------- */

/* exist */
int		ft_cmd_exist(char *cmd);
char	*ft_get_env(char *key, t_env *env);

#endif