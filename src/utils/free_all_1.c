/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:31:40 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/08 17:23:49 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_redir(t_cmd_line *cmd)
{
	t_cmd_line	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->redir)
		{
			if (tmp->redir->file_here_doc)
			{
				// a voir si on doit unlink ici, meme si je pense quon va devoir unlink 
				// a la fin de chaque cmd, donc changer de place le unlink a la fin dune commande.
				unlink(tmp->redir->file_here_doc);
				free(tmp->redir->file_here_doc);
			}
			free(tmp->redir);
			tmp->redir = NULL;
		}
		tmp = tmp->next;
	}
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
		ft_free_redir(data->cmd_list);
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

void	free_all(t_data *data)
{
	ft_free_both_env(data);
	clear_lists(data);
	if (data)
		free(data);
}
