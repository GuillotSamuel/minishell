/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:13:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/03/16 20:24:00 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status;

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

static void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = 130;
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	char	*line;
	t_env	**env;
	t_env	**secret;

	line = NULL;
	if (ac == 0 || !av || ac > 1)
		return (printf("No args required\n"), 0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (ERROR_G);
	data->cmd_list = NULL;
	data->env_array = NULL;
	data->pipes_fd = NULL;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	ft_init_lst_env((const char **)envp);
	env = ft_singletone_env();
	secret = dup_secret_env(env);
	data->env = env;
	data->secret_env = secret;
	minishell(line, data);
	return (0);
}
