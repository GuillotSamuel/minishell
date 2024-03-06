/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:46:53 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/06 17:56:52 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_exit_status;

void    exec_builtin(t_cmd_line *cmd, t_data *data)
{
    if (ft_cmd_exist(cmd) == OK)
    {
        execve(cmd->args[0], cmd->args[1], data->env);
		g_exit_status = 0;
    }
    else
    {
        ft_printf("Command '%s' not found\n", cmd->command);
		g_exit_status = 127;
	}
}

void    exec_builtin(t_cmd_line *cmd, t_data *data)
{
	if (ft_strcmp(cmd->command, "cd") == 0)
		ft_cd(cmd, data);
	else if (ft_strcmp(cmd->command, "echo") == 0)
		ft_echo(cmd);
	else if (ft_strcmp(cmd->command, "env") == 0)
		ft_env(data);
	else if (ft_strcmp(cmd->command, "exit") == 0)
		ft_exit(cmd, data);
	else if (ft_strcmp(cmd->command, "export") == 0)
		ft_export(cmd, data);
	else if (ft_strcmp(cmd->command, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(cmd->command, "unset") == 0)
		ft_unset(cmd, data);
}