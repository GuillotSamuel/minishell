/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:31:40 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/15 17:59:15 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_data_env_array(t_data *data)
{
	int	i;

	i = 0;
	if (data->env_array)
	{
		while (data->env_array[i])
		{
			if (data->env_array[i])
				free(data->env_array[i]);
			i++;
		}
		free(data->env_array);
	}
	data->env_array = NULL;
}

void	ft_free_redir(t_cmd_line *cmd)
{
	t_cmd_line	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->redir)
		{
			free(tmp->redir);
			tmp->redir = NULL;
		}
		tmp = tmp->next;
	}
}

static void	clear_token_list(t_token **token_list)
{
	t_token	*current;
	t_token	*tmp;

	current = *token_list;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp->token);
		free(tmp);
	}
	*token_list = NULL;
}

void	clear_lists(t_data *data)
{
	t_cmd_line	*current;
	t_cmd_line	*tmp;

	current = data->cmd_list;
	while (current)
	{
		ft_free_array(current->args);
		ft_free_redir(current);
		clear_token_list(&(current->token_list));
		tmp = current;
		current = current->next;
		if (tmp->cmd)
			free(tmp->cmd);
		free(tmp);
	}
	data->cmd_list = NULL;
}

void	free_all(t_data *data)
{
	if (data->pipes_fd)
		free_pipes_fd(data);
	ft_free_both_env(data);
	clear_lists(data);
	free_data_env_array(data);
	if (data)
		free(data);
}
