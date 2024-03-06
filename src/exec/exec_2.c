/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:46:53 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/06 21:50:08 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int g_exit_status;

char	**convert_token_list_to_array(t_cmd_line *cmd, t_data *data)
{
	t_cmd_line	*token_list_dup;
	int			token_counter;

	token_list_dup = cmd->token_list;
	while (token_list_dup != NULL)
	{
		token_counter++;
		token_list_dup = token_list_dup->next;
	}
	token_list_dup = cmd->token_list;
	cmd->args = malloc(sizeof(char *) * (token_counter + 1));
	if (cmd->args == NULL)
		exit_error(data);
	while (token_list_dup != NULL)
	{
		cmd->args[token_counter] = ft_strdup(token_list_dup->token);
		if (cmd->args[token_counter] == NULL)
			exit_error(data);
		token_counter--;
		token_list_dup = token_list_dup->next;
	}

}

void	exec_builtins(t_cmd_line *cmd, t_data *data)
{
	if (ft_cmd_exist(cmd) == OK)
	{
		execve(cmd->args[0], cmd->args[1], data->env);
		g_exit_status = 0;
	}
	else
	{
		ft_printf("Command '%s' not found\n", cmd->command);
		g_exit_status = 127;
	}
}

void	exec_external(t_cmd_line *cmd, t_data *data)
{
/* 	if (ft_strcmp(cmd->command, "cd") == 0)
		ft_cd(cmd, data);
	else  */if (ft_strcmp(cmd->command, "echo") == 0)
		ft_echo();
	else if (ft_strcmp(cmd->command, "env") == 0)
		ft_env(data);
	else if (ft_strcmp(cmd->command, "exit") == 0)
		ft_exit(cmd, data);
	else if (ft_strcmp(cmd->command, "export") == 0)
		ft_export(cmd, data);
	else if (ft_strcmp(cmd->command, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(cmd->command, "unset") == 0)
		ft_unset(cmd, data);
}

void	convert_env_to_array(t_env **env, t_data *data)
{
	char	**env_array;
	int		i;

	i = 0;
	while (env != NULL)
	{
		i++;
		env = env->next;
	}
	env_array = malloc(sizeof(char *) * (i + 1));
	if (env_array == NULL)
		exit_error(data);
	i = 0;
	while (env != NULL)
	{
		env_array[i] = ft_strjoin(env->key, env->value);
		i++;
		env = env->next;
	}
	env_array[i] = NULL;
	data->env_array = env_array;
}

/* void convert_env_to_array(t_env *env, t_data *data) {
    char **env_array;
    int i = 0;
    t_env *temp = env;

    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    env_array = malloc(sizeof(char *) * (i + 1));
    if (env_array == NULL)
        exit_error(data);
    temp = env;
    i = 0;
    while (temp != NULL) {
        env_array[i] = ft_strjoin(temp->key, temp->value);
        if (env_array[i] == NULL)
            exit_error(data);
        i++;
        temp = temp->next;
    }
    env_array[i] = NULL;
    data->env_array = env_array;
} */ // TO REMPLACE THE OTHER ONE ?
