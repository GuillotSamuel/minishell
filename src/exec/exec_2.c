/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:46:53 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/07 13:34:36 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int g_exit_status;

static void	ft_token_counter(t_token *token_list_dup, int *token_counter)
{
	*token_counter = -1;
	while (token_list_dup != NULL)
	{
		(*token_counter)++;
		token_list_dup = token_list_dup->next;
	}
}

static void	convert_token_list_to_array(t_cmd_line *cmd, t_data *data)
{
	t_token		*token_list_dup;
	int			token_counter;
	int			i;

	i = 0;
	if (data->args != NULL)
		free_data_args(data);
	token_list_dup = cmd->token_list;
	ft_token_counter(token_list_dup, &token_counter);
	token_list_dup = cmd->token_list;
	token_list_dup = token_list_dup->next;
	data->args = malloc(sizeof(char *) * (token_counter + 1));
	if (data->args == NULL)
		exit_error(data);
	while (token_list_dup != NULL)
	{
		data->args[i] = ft_strdup(token_list_dup->token);
		if (data->args[i] == NULL)
			exit_error(data);
		i++;
		token_list_dup = token_list_dup->next;
	}
	data->args[i] = NULL;
}

void	exec_builtins(t_cmd_line *cmd, t_data *data)
{
	if (ft_cmd_exist(cmd->cmd) == OK)
	{
		execve(cmd->args[0], cmd->args, data->env_array);
		g_exit_status = 0;
	}
	else
	{
		ft_printf("Command '%s' not found\n", cmd->args[0]);
		g_exit_status = 127;
	}
}

void	exec_externals(t_cmd_line *cmd, t_data *data)
{
	convert_token_list_to_array(cmd, data);
/* 	if (ft_strcmp(cmd->command, "cd") == 0)
		ft_cd(cmd, data);
	else  */if (ft_strcmp(cmd->token_list->token, "echo") == 0)
		ft_echo(data->args);
	else if (ft_strcmp(cmd->token_list->token, "exit") == 0)
		ft_exit(data->args);
/* 	else if (ft_strcmp(cmd->token_list->token, "export") == 0)
		ft_export(cmd, data); */
	else if (ft_strcmp(cmd->token_list->token, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(cmd->token_list->token, "unset") == 0)
		ft_unset((*data->env)->key);
}

void	convert_env_to_array(t_env **env, t_data *data)
{
	char	**env_array;
	int		i;
	t_env	*env_dup;

	i = 0;
	env_dup = *env;
	while (env_dup != NULL)
	{
		i++;
		env_dup = env_dup->next;
	}
	env_array = malloc(sizeof(char *) * (i + 1));
	if (env_array == NULL)
		exit_error(data);
	i = 0;
	while (env_dup != NULL)
	{
		env_array[i] = ft_strjoin(env_dup->key, env_dup->value);
		i++;
		env_dup = env_dup->next;
	}
	env_array[i] = NULL;
	data->env_array = env_array;
}
