/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:49:29 by azbk              #+#    #+#             */
/*   Updated: 2024/03/14 17:01:12 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	check_builtin(char *arg)
{
	if (!arg)
		return (FAIL);
	if (ft_strcmp(arg, "echo") == 0)
		return (1);
	if (ft_strcmp(arg, "cd") == 0)
		return (1);
	if (ft_strcmp(arg, "pwd") == 0)
		return (1);
	if (ft_strcmp(arg, "export") == 0)
		return (1);
	if (ft_strcmp(arg, "unset") == 0)
		return (1);
	if (ft_strcmp(arg, "env") == 0)
		return (1);
	if (ft_strcmp(arg, "exit") == 0)
		return (1);
	return (FAIL);
}

int	exec_builtin(t_cmd_line *cmd, t_data *data)
{
	if (ft_strcmp(cmd->args[0], "echo") == 0)
		ft_echo(cmd->args);
	if (ft_strcmp(cmd->args[0], "cd") == 0)
		ft_cd(&cmd->args[1], data);
	if (ft_strcmp(cmd->args[0], "pwd") == 0)
		ft_pwd();
	if (ft_strcmp(cmd->args[0], "export") == 0)
		ft_export(cmd->args, data);
	if (ft_strcmp(cmd->args[0], "unset") == 0)
		ft_unset(cmd, data);
	if (ft_strcmp(cmd->args[0], "env") == 0)
		ft_print_env(data->env);
	if (ft_strcmp(cmd->args[0], "exit") == 0)
		ft_exit(&cmd->args[1], data);
	return (0);
}

int	exec_builtin_one_cmd(t_cmd_line *cmd, t_data *data)
{
	int	original_stdout;

	original_stdout = dup(STDOUT_FILENO);
	dup2(cmd->redir->fd_out, 1);
	if (ft_strcmp(cmd->args[0], "echo") == 0)
		ft_echo(cmd->args);
	if (ft_strcmp(cmd->args[0], "cd") == 0)
		ft_cd(&cmd->args[1], data);
	if (ft_strcmp(cmd->args[0], "pwd") == 0)
		ft_pwd();
	if (ft_strcmp(cmd->args[0], "export") == 0)
		ft_export(cmd->args, data);
	if (ft_strcmp(cmd->args[0], "unset") == 0)
		ft_unset(cmd, data);
	if (ft_strcmp(cmd->args[0], "env") == 0)
		ft_print_env(data->env);
	if (ft_strcmp(cmd->args[0], "exit") == 0)
		ft_exit(&cmd->args[1], data);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	close(cmd->redir->fd_out);
	close(cmd->redir->fd_in);
	return (0);
}
