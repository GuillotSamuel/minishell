/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:49:51 by azbk              #+#    #+#             */
/*   Updated: 2024/03/16 14:04:02 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

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
		g_exit_status = 1;
        return (FAIL);
    }
    redir->fd_in = fd;
    return (OK);
}
int write_or_overwrite_file(t_redir *redir, t_token *token_list, enum_type type)
{
    int fd;

    if (redir->fd_out != 1)
    {
        close(redir->fd_out);
    }
    redir->fd_out = 1;
    if (type == CREAT_FILE)
        fd = open(token_list->token, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    else
        fd = open(token_list->token, O_WRONLY | O_CREAT | O_APPEND, 0777);
    if (fd < 0)
    {
        ft_putstr_fd("minishell: ", 2);
        ft_putstr_fd(token_list->token, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
		g_exit_status = 1;
        return (FAIL);
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
            {
			    return (FAIL);
            }
		}
		token = token->next;
	}
	return (OK);
}
