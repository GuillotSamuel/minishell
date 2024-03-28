/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:13:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/03/28 11:17:06 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		g_exit_status;

void	minishell(t_data *data)
{
	while (true)
	{
		data->line_free
			= readline("\001\033[1;33m\002MonMinishell>\001\033[0m\002 ");
		if (data->line_free == NULL)
		{
			ft_printf("exit\n");
			free(data->line_free);
			ft_free_both_env(data);
			free(data);
			break ;
		}
		else if (data->line_free != NULL && strlen(data->line_free) > 0)
		{
			add_history(data->line_free);
			if (parsing(data->line_free, data) == SUCCESS)
			{
				init_exec(data);
			}
			free_pipes_fd(data);
			clear_lists(data);
		}
		else
			free(data->line_free);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	if (ac == 0 || !av || ac > 1)
		return (printf("No args required\n"), 1);
	g_exit_status = 0;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	if (init_data(&data, envp) == ERROR_G)
		return (ERROR_G);
	minishell(data);
	return (0);
}
