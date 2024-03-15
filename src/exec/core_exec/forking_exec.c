/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:41:20 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/15 16:03:34 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	command_or_builtin(t_data *data, t_cmd_line *cmd_list)
{
	t_cmd_line	*cmd_list_dup;
	char		*path;
	
	
	cmd_list_dup = cmd_list;
	if (check_builtin(cmd_list_dup->args[0]) == 1)
	{
		exec_builtin(cmd_list_dup, data);
		free_all(data);
		exit(0); // TO ADD WHEN FORKING IS DONE
	}
	path = ft_cmd_exist(cmd_list_dup->token_list->token);
	if (path != VAR_NOT_FOUND)
	{
		ft_execve_exec(path, cmd_list_dup, data);
	}
	free_pipes_fd(data);
	free_all(data);
	exit(0);
}


// static void	close_all_fd(t_data *data)
// {
// 	int	i;
// 	int	num_children;

// 	i = 0;
// 	num_children = cmd_nb(data->cmd_list);
// 	while (i < num_children)
// 	{
// 		close(data->pipes_fd[i][0]);
// 		close(data->pipes_fd[i][1]);
// 		i++;
// 	}
// }

// static void	ft_wait_children(int num_children, pid_t *pids)
// {
// 	int	i;
// 	//int	status;

// 	i = 0;
// 	while (i < num_children)
// 	{
// 		waitpid(pids[i], NULL, 0);
// 		i++;
// 	}
// }

void forking_exec(t_data *data) {
    t_cmd_line *cmd_list = data->cmd_list;
    int num_children = cmd_nb(data->cmd_list);
    pid_t pids[num_children];
    int i = 0;

    // Boucle pour créer les processus enfants
    while (cmd_list) {
        pids[i] = fork();
        if (pids[i] < 0) {
            perror("fork");
            free_all(data); // Assurez-vous que cette fonction libère toutes les ressources correctement
            exit(EXIT_FAILURE);
        } else if (pids[i] == 0) { // Dans le processus enfant
            dup2(cmd_list->redir->fd_in, STDIN_FILENO);
            dup2(cmd_list->redir->fd_out, STDOUT_FILENO);
            // Fermer les descripteurs inutilisés dans l'enfant
            if (cmd_list->redir->fd_in != 0)
                close(cmd_list->redir->fd_in);
            if (cmd_list->redir->fd_out != 1)
                close(cmd_list->redir->fd_out);
            // Fermeture des pipes inutilisés dans le processus enfant
            for (int j = 0; j < num_children - 1; j++) {
                close(data->pipes_fd[j][0]);
                close(data->pipes_fd[j][1]);
            }
            command_or_builtin(data, cmd_list);
            // command_or_builtin doit appeler exit après l'exécution
        }
        cmd_list = cmd_list->next;
        i++;
    }

    // Fermeture des pipes dans le processus parent
    for (i = 0; i < num_children - 1; i++) {
        close(data->pipes_fd[i][0]);
        close(data->pipes_fd[i][1]);
    }

    // Attente de tous les processus enfants
    for (i = 0; i < num_children; i++) {
        waitpid(pids[i], NULL, 0);
    }
}
