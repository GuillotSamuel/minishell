/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:14:54 by azbk              #+#    #+#             */
/*   Updated: 2024/03/14 18:13:52 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/minishell.h"

extern int g_exit_status;


int	cmd_nb(t_cmd_line *cmd)
{
	int			i;
	t_cmd_line	*tmp;

	i = 0;
	tmp = cmd;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static int	init_pipes(t_data *data)
{
	t_cmd_line	*cmd_list_tmp;
	int			i;

	cmd_list_tmp = data->cmd_list;
	i = 0;
	data->pipes_fd = malloc(sizeof(int*) * (cmd_nb(data->cmd_list) + 1));
	data->pipes_fd = malloc(sizeof(int *) * (cmd_nb(data->cmd_list) + 1));
	if (!data->pipes_fd)
		return (ERROR);
	while (cmd_list_tmp)
	{
		data->pipes_fd[i] = malloc(sizeof(int) * 2);
		if (!data->pipes_fd[i])
			return (ERROR);
		if (pipe(data->pipes_fd[i]) == -1)
			return (ERROR);
		cmd_list_tmp = cmd_list_tmp->next;
		i++;
	}
	data->pipes_fd[i] = NULL;
	return (OK);
}

int start_exec(t_data *data)
{
	t_cmd_line *cmd;
	int nb_cmd;
	
	nb_cmd = 0;

	cmd = data->cmd_list;
	while (cmd)
	{
		if (open_all_redirections(cmd) == -1)
			return (FAIL);
		cmd = cmd->next;
		nb_cmd ++;
	}
    if (nb_cmd == 1 && check_builtin(data->cmd_list->args[0]) == 1)
    {
        if (exec_builtin_one_cmd(data->cmd_list, data) == -1)
            return (FAIL);
    }
	else
		forking_exec(data); 
    return (OK);
}

int init_exec(t_data *data)
{
	init_pipes(data);
	start_exec(data);
	free_pipes_fd(data);
	return (OK);
}
