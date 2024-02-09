/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:13:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/09 15:24:14 by sguillot         ###   ########.fr       */
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
			ft_printf("exit\n");
			free(line);
			break;
		}
		if (line != NULL && strlen(line) > 0)
		{			add_history(line);
			parsing(line, data);
			ft_printf("parsing done\n");
			ft_printf("history added\n");
			clear_lists(data);
		}
	}
}

void	execute_command(char *line, t_data *data /* , char **env */)
{
	ft_printf("execute_command\n");
	init_struct(data);
	ft_printf("structures initiliazed\n");
	minishell(line, data /* , env */);
	ft_printf("minishell done\n");
	free_all(data /* , env */);
	ft_printf("free_all done\n");
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
		return (-1);
	// env = init_env(envp);
	execute_command(line, data /* , env */);
	/* Revoir le free */
	free(line);
	return (0);
}
