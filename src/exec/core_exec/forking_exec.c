/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:41:20 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/14 18:46:39 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	command_or_builtin(t_data *data)
{
	t_cmd_line	*cmd_list_dup;
	char		*path;

	cmd_list_dup = data->cmd_list;
	if (check_builtin(cmd_list_dup->cmd) == 1)
	{
		printf("BUILTIN\n");
		fflush(stdout);
		exec_builtin(cmd_list_dup, data);
		return ; // TO REMOVE WHEN FORKING IS DONE
		//exit(NULL); // TO ADD WHEN FORKING IS DONE
	}
	path = ft_cmd_exist(cmd_list_dup->token_list->token);
	if (path != VAR_NOT_FOUND)
	{
		ft_execve_exec(path, cmd_list_dup, data);
	}
}

void	forking_exec(t_data *data)
{
	if (data->cmd_list->redir->fd_in != 0)
		dup2(data->cmd_list->redir->fd_in, 0);
	if (data->cmd_list->redir->fd_out != 1)
		dup2(data->cmd_list->redir->fd_out, 1);
	command_or_builtin(data);
}
