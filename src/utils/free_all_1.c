/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:31:40 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/07 13:06:18 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_data_env_array(t_data *data)
{
	int	i;

	i = 0;
	if (data->env_array)
	{
		while (data->env_array[i])
		{
			free(data->env_array[i]);
			i++;
		}
		free(data->env_array);
	}
	data->env_array = NULL;
}

void	free_data_args(t_data *data)
{
	int	i;

	i = 0;
	if (data->args)
	{
		while (data->args[i])
		{
			free(data->args[i]);
			i++;
		}
		free(data->args);
	}
	data->args = NULL;
}

void	clear_lists(t_data *data)
{
	t_cmd_line	*cmd_list_dup;
	t_cmd_line	*tmp_cmd;
	t_token		*token_list_dup;
	t_token		*tmp_token;

	cmd_list_dup = data->cmd_list;
	while (cmd_list_dup)
	{
		ft_free_array(cmd_list_dup->args);
		token_list_dup = cmd_list_dup->token_list;
		while (token_list_dup)
		{
			tmp_token = token_list_dup;
			token_list_dup = token_list_dup->next;
			free(tmp_token->token);
			if (tmp_token)
				free(tmp_token);
		}
		tmp_cmd = cmd_list_dup;
		cmd_list_dup = cmd_list_dup->next;
		if (tmp_cmd->cmd)
			free(tmp_cmd->cmd);
		free(tmp_cmd);
	}
	data->cmd_list = NULL;
}

void free_all(t_data *data)
{
	ft_free_both_env(data);
	clear_lists(data);
	free_data_env_array(data);
	free_data_args(data);
	if (data)
		free(data);
	// free_env(env);
}
