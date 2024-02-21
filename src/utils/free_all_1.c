/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:31:40 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/21 13:51:28 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clear_lists(t_data *data)
{
	t_cmd_line	*cmd_list_dup;
	t_cmd_line	*tmp_cmd;
	t_token		*token_list_dup;
	t_token		*tmp_token;

	cmd_list_dup = data->cmd_list;
	while (cmd_list_dup)
	{
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
		data->cmd_list = NULL;
	}
}

void free_all(t_data *data)
{
	clear_lists(data);
	if (data)
		free(data);
	// free_env(env);
}
