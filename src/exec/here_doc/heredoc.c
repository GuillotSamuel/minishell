/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:12:58 by azbk              #+#    #+#             */
/*   Updated: 2024/03/08 17:19:40 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"


static void fill_here_doc(int fd, char *token)
{
    char *line;

    while(true)
    {
        line = readline("> ");
        if (line == NULL)
        {
            return ;
        }
        if (ft_strcmp(line, token) == 0)
        {
            free(line);
            return ;
        }
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);
        free(line);
    }
    free(line);
}

int start_here_doc(t_redir *redir, t_token *token_list)
{
	int fd;
	char *file;
	
	if (redir->fd_in != 0)
		close(redir->fd_in);
	file = create_random_name();
	if (file == NULL)
		return (FAIL);
	fd = open(file, O_CREAT | O_EXCL | O_RDWR, 0644);
	if (fd == -1)
	{
		return (FAIL);
	}
	redir->fd_in = fd;
	fill_here_doc(fd, token_list->token);
	if (redir->file_here_doc)
	{
		unlink(redir->file_here_doc);
		free(redir->file_here_doc);
		redir->file_here_doc = NULL;		
	}
	redir->file_here_doc = file;
	return (OK);
}
