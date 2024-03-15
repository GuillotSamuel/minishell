/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:41:20 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/15 11:44:25 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	command_or_builtin(t_data *data, t_cmd_line *cmd_list)
{
	t_cmd_line	*cmd_list_dup;
	char		*path;
	
	cmd_list_dup = cmd_list;
	if (check_builtin(cmd_list_dup->args[0]) == 1)
	{
		fflush(stdout);
		exec_builtin(cmd_list_dup, data);
		free_all(data);
		exit(0); // TO ADD WHEN FORKING IS DONE
	}
	path = ft_cmd_exist(cmd_list_dup->token_list->token);
	if (path != VAR_NOT_FOUND)
	{
		ft_execve_exec(path, cmd_list_dup, data);
	}
}

void	forking_exec(t_data *data)
{
	t_cmd_line	*cmd_list;

	cmd_list = data->cmd_list;
	int		i;
	int		num_children;
	pid_t	pid;
	
	i = 0;
	num_children = cmd_nb(data->cmd_list);
	while (i < num_children)
	{
		pid = fork();
		if (pid < 0)
		{
			free_all(data);
		}
		else if (pid == 0)
		{
			//redirect_io(data);
			command_or_builtin(data, cmd_list);
			//exit (0);
		}
		else if (pid > 0)
		{
			wait(NULL);
		}
		i++;
		cmd_list = cmd_list->next;
	}
}
