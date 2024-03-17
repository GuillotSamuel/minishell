/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:13:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/03/17 17:41:26 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		g_exit_status;

void	minishell(char *line, t_data *data)
{
	while (true)
	{
		line = readline("\001\033[1;33m\002MonMinishell>\001\033[0m\002 ");
		if (line == NULL)
		{
			ft_printf("exit\n");
			ft_free_both_env(data);
			free(data);
			free(line);
			break ;
		}
		else if (line != NULL && strlen(line) > 0)
		{
			add_history(line);
			if (parsing(line, data) == SUCCESS)
			{
				init_exec(data);
			}
			free_pipes_fd(data);
			clear_lists(data);
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	char	*line;

	if (ac == 0 || !av || ac > 1)
		return (printf("No args required\n"), 0);
	line = NULL;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	if (init_data(&data, envp) == ERROR_G)
		return (ERROR_G);
	minishell(line, data);
	return (0);
}
