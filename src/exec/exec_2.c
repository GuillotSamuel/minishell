/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:46:53 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/10 17:19:38 by sguillot         ###   ########.fr       */
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
	if (data->args_array != NULL)
		free_data_args(data);
	token_list_dup = cmd->token_list;
	ft_token_counter(token_list_dup, &token_counter);
	token_list_dup = cmd->token_list;
	token_list_dup = token_list_dup->next;
	data->args_array = malloc(sizeof(char *) * (token_counter + 1));
	if (data->args_array == NULL)
		exit_error(data);
	while (token_list_dup != NULL)
	{
		data->args_array[i] = ft_strdup(token_list_dup->token);
		if (data->args_array[i] == NULL)
			exit_error(data);
		i++;
		token_list_dup = token_list_dup->next;
	}
	data->args_array[i] = NULL;
}

void ft_print_args_array(char **args_array)
{
	int i;

	i = 0;
	ft_printf("\n");
	while (args_array[i] != NULL)
	{
		ft_printf("data->args_array[%d] = %s\n", i, args_array[i]);
		i++;
	}
	ft_printf("data->args_array[%d] = %s\n\n", i, args_array[i]);
}

void ft_print_env_array(char **env_array)
{
	int i;

	i = 0;
	ft_printf("\n");
	while (env_array[i] != NULL)
	{
		ft_printf("data->env_array[%d] = %s\n", i, env_array[i]);
		i++;
	}
	ft_printf("data->env_array[%d] = %s\n\n", i, env_array[i]);
}

void	exec_externals(t_cmd_line *cmd, t_data *data)
{
	ft_print_env_array(data->env_array);
	ft_print_args_array(cmd->args);
	if (ft_cmd_exist(cmd->cmd) == OK)
	{
		if (execve(cmd->args[0], cmd->args, data->env_array) == -1)
			exit_error(data);
		g_exit_status = 0;
	}
	else
	{
		ft_printf("Command '%s' not found\n", cmd->args[0]);
		g_exit_status = 127;
	}
}

void	exec_builtins(t_cmd_line *cmd, t_data *data)
{
	convert_token_list_to_array(cmd, data);
/* 	if (ft_strcmp(cmd->command, "cd") == 0)
		ft_cd(cmd, data);
	else  */if (ft_strcmp(cmd->token_list->token, "echo") == 0)
		ft_echo(data->args_array);
	else if (ft_strcmp(cmd->token_list->token, "exit") == 0)
		ft_exit(data->args_array);
/* 	else if (ft_strcmp(cmd->token_list->token, "export") == 0)
		ft_export(cmd, data); */
	else if (ft_strcmp(cmd->token_list->token, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(cmd->token_list->token, "unset") == 0)
		ft_unset(cmd->token_list->next->token);
	else
		ft_printf("Command '%s' not found\n", cmd->token_list->token);
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
	env_dup = *env;
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
