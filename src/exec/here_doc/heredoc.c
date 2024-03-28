/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:12:58 by azbk              #+#    #+#             */
/*   Updated: 2024/03/28 11:59:14 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

static int	print_end_of_file(char *token)
{
	ft_putstr_fd("minishell: warning: ", 2);
	ft_putstr_fd("here-document delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("')\n", 2);
	return (-1);
}

static int	fill_here_doc(int fd, char *token)
{
	char	*line;

	while (true)
	{
		line = readline("> ");
		if (g_exit_status == 130)
		{
			free(line);
			ft_printf("\n");
			return (ERROR_HERE_DOC);
		}	
		if (line == NULL)
		{	
			return (print_end_of_file(token));
		}
		if (ft_strcmp(line, token) == 0)
		{
			free(line);
			return (1);
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
}

static int	handle_ctrl_c(int fd, char *file, int dup_fd)
{
	dup2(dup_fd, 0);
	close(fd);
	unlink(file);
	free(file);
	signal(SIGINT, handle_sigint);
	return (-2);
}

static void	close_fd_redir(t_redir *redir)
{
	g_exit_status = 0;
	if (redir->fd_in != 0)
		close(redir->fd_in);
	if (redir->file_here_doc)
	{
		unlink(redir->file_here_doc);
		free(redir->file_here_doc);
		redir->file_here_doc = NULL;
	}
}

int	start_here_doc(t_redir *redir, t_token *token_list)
{
	int		fd;
	int		dup_fd;
	char	*file;

	close_fd_redir(redir);
	file = create_random_name();
	if (file == NULL)
		return (FAIL);
	fd = open(file, O_CREAT | O_EXCL | O_RDWR, 0644);
	if (fd == -1)
		return (FAIL);
	dup_fd = dup(STDIN_FILENO);
	signal(SIGINT, handle_sigint_here);
	if (fill_here_doc(fd, token_list->token) == -2)
	{
		return (handle_ctrl_c(fd, file, dup_fd));
	}
	signal(SIGINT, handle_sigint);
	close(fd);
	fd = open(file, O_RDONLY);
	redir->fd_in = fd;
	if (fd == -1)
		return (FAIL);
	redir->file_here_doc = file;
	return (OK);
}
