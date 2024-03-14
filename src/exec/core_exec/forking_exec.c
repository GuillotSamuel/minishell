/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:41:20 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/14 17:00:26 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	forking_exec(t_data *data)
{
	t_cmd_line	*cmd_list_dup;
	char		*path;

	cmd_list_dup = data->cmd_list;
	if (check_builtin(cmd_list_dup->cmd) == SUCCESS)
	{
		exec_builtin(cmd_list_dup, data);
		//exit(NULL); // TO ADD WHEN FORKING IS DONE
	}
	path = ft_cmd_exist(cmd_list_dup->cmd);
	if (path != VAR_NOT_FOUND)
	{
		ft_execve_exec(path, cmd_list_dup, data);
	}
}
