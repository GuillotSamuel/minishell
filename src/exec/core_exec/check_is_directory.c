/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:59:05 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/19 14:39:38 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

static void	permission_denied(t_data *data, char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	g_exit_status = 126;
	free(data->pids);
	free_all(data);
	exit(g_exit_status);
}

static void	not_file_or_directory(t_data *data, char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	g_exit_status = 127;
	free(data->pids);
	free_all(data);
	exit(g_exit_status);
}

static void	is_directory(t_data *data, char *cmd)
{
	DIR	*dir;

	dir = opendir(cmd);
	if (dir)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Is a directory\n", 2);
		g_exit_status = 126;
		free(data->pids);
		free_all(data);
		closedir(dir);
		exit(g_exit_status);
	}
}

void	ft_check_is_directory(t_data *data, char *cmd)
{
	if ((cmd[0] != '\0' && cmd[1] != '\0' && cmd[2] != '\0' && cmd[0] == '.'
			&& cmd[1] == '/' && access(cmd, F_OK) == -1) || (cmd[0] != '\0'
			&& cmd[1] != '\0' && cmd[0] == '/' && access(cmd, F_OK) == -1))
	{
		not_file_or_directory(data, cmd);
	}
	else if ((cmd[0] != '\0' && cmd[1] != '\0' && cmd[2] != '\0'
			&& cmd[0] == '.' && cmd[1] == '/' && access(cmd, X_OK) == -1)
		|| (cmd[0] && cmd[0] == '/' && access(cmd, X_OK) == -1))
	{
		permission_denied(data, cmd);
	}
	else if ((cmd[0] != '\0' && cmd[1] != '\0' && cmd[2] != '\0'
			&& cmd[0] == '.' && cmd[1] == '/') || (cmd[0] != '\0'
			&& cmd[1] != '\0' && cmd[0] == '/'))
	{
		is_directory(data, cmd);
	}
}
