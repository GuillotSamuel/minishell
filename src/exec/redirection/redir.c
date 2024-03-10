/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:49:51 by azbk              #+#    #+#             */
/*   Updated: 2024/03/08 16:18:01 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int file_in(t_redir *redir, t_token *token_list)
{
    int fd;

    if (redir->fd_in != 0)
        close(redir->fd_in);
    redir->fd_in = 0;
    fd = open(token_list->token, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("minishell: ", 2);
        ft_putstr_fd(token_list->token, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        return (ERROR);
    }
    redir->fd_in = fd;
    return (OK);
}
int write_or_overwrite_file(t_redir *redir, t_token *token_list, enum_type type)
{
    int fd;

    if (redir->fd_out != 0)
        close(redir->fd_out);
    redir->fd_out = 0;
    if (type == CREAT_FILE)
        fd = open(token_list->token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    else
        fd = open(token_list->token, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0)
    {
        ft_putstr_fd("minishell: ", 2);
        ft_putstr_fd(token_list->token, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        return (ERROR);
    }
    redir->fd_out = fd;
    return (OK);
}
int open_all_redirections(t_cmd_line *cmd)
{
	t_token *token;
	
	token = cmd->token_list;
	while (token)
	{
		if(token->type == LIMITOR)
		{
			if (start_here_doc(cmd->redir, token) == -1)
				return (FAIL);	
		}
		else if (token->type == OPEN_FILE)
		{
			if (file_in(cmd->redir, token) == -1)
				return (FAIL);
		}
		else if(token->type == CREAT_FILE || token->type == WRITE_FILE)
		{
			if (write_or_overwrite_file(cmd->redir, token, token->type) == -1)
			    return (FAIL);
		}
		token = token->next;
	}
	// a supprrrr
	if (cmd->redir->fd_in != 0)
		close(cmd->redir->fd_in);
	if (cmd->redir->fd_out != 0)
		close(cmd->redir->fd_out);
	return (OK);
}
