/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:13:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/25 13:55:18 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status;

void	minishell(char *line, t_data *data/* , char **env */)
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

// START TEST 
void ft_print_env(t_env **env)
{
    t_env *cur;

    cur = *env;
    while (cur)
    {   
        printf("%s\n", cur->str);
        // printf("key = %s\n", cur->key);
        // printf("value = %s\n", cur->value);
        cur = cur->next;
    }
}
// END TEST

int	main(int ac, char **av, char **envp )
{
	t_data	*data;
	// char	**env;
	char	*line;

	line = NULL;
	if (ac == 0 || !av)
		return (0);
	data = malloc(sizeof(t_data));
	// recupere la value grace a la key echo $PATH
	// ajoute une key value export bonjour=test
	// change la value grace a la key export bonjour=bonjour
	// supprime un maillon grace a la key unset bonjour
/* 	t_env **head;
	ft_envaddback(*head, "bonjour", "test");
	ft_envgetvalue(*head, "bonjour");
	ft_envchangevalue(*head, "bonjour", "bonjour");
	ft_envdelone(*head, "bonjour");
	data->env = head; */
	if (!data)
		return (ERROR_G);
	data->cmd_list = NULL;
	data->env = NULL;
	//env = init_env(envp);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	ft_init_lst_env((const char**)envp);
	t_env **env = ft_singletone_env();
	t_env **secret = dup_secret_env(env);
	data->env = secret;
	/* TEST */
	// ft_print_env(env);
	// ft_printf("--------------------------------------------------------------------------------\n");
	// ft_print_env(secret);
	/* END TEST */
	minishell(line, data /* , env */);
	return (0);
}
