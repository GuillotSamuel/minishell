/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:31:40 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/19 15:09:55 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clear_lists(t_data *data)
{
	t_cmd_line	*cmd;
	t_cmd_line	*tmp_cmd;
	t_token		*token;
	t_token		*tmp_token;

	cmd = data->cmd_list;
	while (cmd)
	{
		if (cmd->token_list)
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
		if (tmp_cmd)
			free(tmp_cmd);
	}
}

void	free_all(t_data *data)
{
	clear_lists(data);
	if (data)
		free(data);
	// free_env(env);
}
