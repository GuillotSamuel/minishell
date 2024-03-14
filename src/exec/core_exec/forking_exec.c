/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:41:20 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/14 17:38:06 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	forking_exec(t_data *data)
{
	t_cmd_line	*cmd_list_dup;
	char		*path;

	if (data->cmd_list->redir->fd_in != 0)
		dup2(data->cmd_list->redir->fd_in, 0);
	if (data->cmd_list->redir->fd_out != 1)
		dup2(data->cmd_list->redir->fd_out, 1);
	cmd_list_dup = data->cmd_list;
	if (check_builtin(cmd_list_dup->cmd) == SUCCESS)
	{
		exec_builtin(cmd_list_dup, data);
		//exit(NULL); // TO ADD WHEN FORKING IS DONE
	}
	path = ft_cmd_exist(cmd_list_dup->token_list->token);
	if (path != VAR_NOT_FOUND)
	{
		ft_execve_exec(path, cmd_list_dup, data);
	}
}
