/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:52:41 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/16 19:16:49 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	is_empty_countet(char **args)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (args[i])
	{
		if (args[i][0] == '\0')
			counter++;
		i++;
	}
	return (counter);	
}

static int	args_counter(char **args)
{
	int i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static void	free_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static char **clean_cmd_args(char **args, t_data *data)
{
	char	**new_args;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	new_args = malloc(sizeof(char *)
		* (args_counter(args) - is_empty_countet(args) + 1));
	if (!new_args)
		exit_error(data);
	while (args[i])
    {
        if (args[i][0] != '\0')
        {
            new_args[j] = ft_strdup(args[i]);
            j++;
        }
        i++;
    }
	new_args[j] = NULL;
	free_args(args);
	return (new_args);
}

static bool check_command_is_empty(char **cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i][0] != '\0')
			return (false);
		i++;
	}
	return (true);
}

void	check_args_array_after_expands(t_cmd_line *cmd, t_data *data)
{
	t_cmd_line	*cmd_list_dup;

	cmd_list_dup = cmd;
	while (cmd_list_dup)
	{
		if (check_command_is_empty(cmd_list_dup->args) == false)
		{
			cmd_list_dup->args
				= clean_cmd_args(cmd_list_dup->args, data);
		}
		cmd_list_dup = cmd_list_dup->next;
	}
}
