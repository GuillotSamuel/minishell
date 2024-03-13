/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:13:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/03/13 11:45:12 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status;


void	minishell(char *line, t_data *data)
{
	while (true)
	{
		line = readline("\001\033[1;33m\002MonMinishell>\001\033[0m\002 ");
		if (line == NULL || ft_strncmp(line, "exit", 5) == 0)
		{
			ft_printf("exit\n");
			ft_free_both_env(data);
			free(data);
			free(line);
			break;
		}
		else if (line != NULL && strlen(line) > 0)
		{
			add_history(line);
			parsing(line, data);
		}
	}
}
static void	handle_sigint(int sig) 
{
	(void) sig;
	ft_printf("\n\001\033[1;33m\002MonMinishell>\001\033[0m\002 ");
}

int	main(int ac, char **av, char **envp )
{
	t_data	*data;
	char	*line;

	line = NULL;
	if (ac == 0 || !av)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (ERROR_G);
	data->cmd_list = NULL;
	data->env = NULL;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	ft_init_lst_env((const char**)envp);
	t_env **env = ft_singletone_env();
	t_env **secret = dup_secret_env(env);
	data->env = env;
	data->secret_env = secret;
	
	minishell(line, data);
	return (0);
}
