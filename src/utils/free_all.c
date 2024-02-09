/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:31:40 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/09 15:40:25 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clear_lists(t_data *data)
{
	t_cmd_line *cmd;
	t_cmd_line *tmp_cmd;
	t_token *token;
	t_token *tmp_token;

	cmd = data->cmd_list;
	while (cmd)
	{
		token = cmd->token_list;
		while (token)
		{
			tmp_token = token;
			token = token->next;
			if (tmp_token->token)
				free(tmp_token->token);
			free(tmp_token);
		}
		tmp_cmd = cmd;
		cmd = cmd->next;
		if (tmp_cmd->cmd)
			free(tmp_cmd->cmd);
		free(tmp_cmd);
	}
}

void	free_all(t_data *data)
{
	clear_lists(data);
	if (data->cmp)
		free(data->cmp);
	if (data)
		free(data);
	// free_env(env);
}
