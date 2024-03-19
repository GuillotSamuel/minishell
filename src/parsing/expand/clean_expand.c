/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:52:41 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/19 18:10:43 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	is_empty_counter(char **args)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (args[i] && args[i][0] == '\0')
	{
		counter++;
		i++;
	}
	return (counter);
}

static void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static char	**clean_cmd_args(char **args)
{
	char	**new_args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_args = malloc(sizeof(char *) * (args_counter(args)
				- is_empty_counter(args) + 1));
	if (!new_args)
		return (NULL);
	while (args[i] && args[i][0] == '\0')
		i++;
	while (args[i])
	{
		new_args[j] = ft_strdup(args[i]);
		j++;
		i++;
	}
	new_args[j] = NULL;
	free_args(args);
	return (new_args);
}

static bool	check_command_is_empty(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i][0] != '\0')
			return (false);
		i++;
	}
	return (true);
}

int	check_args_array_after_expands(t_cmd_line *cmd)
{
	t_cmd_line	*cmd_list_dup;

	cmd_list_dup = cmd;
	while (cmd_list_dup)
	{
		if (check_command_is_empty(cmd_list_dup->args) == false)
		{
			cmd_list_dup->args = clean_cmd_args(cmd_list_dup->args);
			if (!cmd_list_dup->args)
				return (ERROR);
		}
		cmd_list_dup = cmd_list_dup->next;
	}
	return (OK);
}
