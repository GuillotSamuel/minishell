/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:14:54 by azbk              #+#    #+#             */
/*   Updated: 2024/03/14 13:10:55 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int g_exit_status;

int start_exec(t_data *data)
{
	t_cmd_line *cmd;
	int nb_cmd;
	
	nb_cmd = 0;

	cmd = data->cmd_list;
	while (cmd)
	{
		if (open_all_redirections(cmd) == -1)
		{
			printf("Error in redirections\n");
			return (FAIL);
		}
		cmd = cmd->next;
		nb_cmd ++;
	}
    if (nb_cmd == 1 && check_builtin(data->cmd_list->args[0]) == 1)
    {
        if (exec_builtin(data->cmd_list, data) == -1)
            return (FAIL);
    }
	//start forking PIPEX 
    return (OK);
}



int init_exec(t_data *data)
{
	// INIT LES PIPES AVANT EXEC 
	start_exec(data);
	return (OK);
}
