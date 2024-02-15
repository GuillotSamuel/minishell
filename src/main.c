/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:13:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/15 17:18:38 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(char *line, t_data *data)
{
	while (true)
	{
		line = readline("\001\033[1;33m\002MonMinishell>\001\033[0m\002 ");
		if (line == NULL || ft_strncmp(line, "exit", 5) == 0)
		{
			free(line);
			break;
		}
		if (line != NULL && strlen(line) > 0)
		{			add_history(line);
			parsing(line, data);
			clear_lists(data);
		}
	}
}

void	execute_command(char *line, t_data *data /* , char **env */)
{
	init_struct(data);
	minishell(line, data /* , env */);
	free_all(data /* , env */);
}

int	main(int ac, char **av /*  , char **envp */)
{
	t_data *data;
	// char **env;
	char *line;

	line = NULL;
	if (ac == 0 || !av)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (ERROR_G);
	// env = init_env(envp);
	//signal(SIGINT, SIG_IGN); // ignore ctrl-c

	execute_command(line, data /* , env */);
	/* Revoir le free */
	free(line);
	return (0);
}
