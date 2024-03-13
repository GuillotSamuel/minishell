/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:31:40 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/13 19:34:47 by azbk             ###   ########.fr       */
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
	ft_free_both_env(data);
	free(data->pid);
	clear_lists(data);
	if (data)
		free(data);
}
