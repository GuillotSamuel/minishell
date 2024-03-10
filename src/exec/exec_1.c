/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:47:10 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/10 17:34:38 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	fill_prev_cmd_node(t_data *data)
{
	t_cmd_line	*cmd_list_dup;
	t_cmd_line	*prev_cmd;

	cmd_list_dup = data->cmd_list;
	prev_cmd = NULL;
	while (cmd_list_dup != NULL)
	{
		cmd_list_dup->prev = prev_cmd;
		prev_cmd = cmd_list_dup;
		cmd_list_dup = cmd_list_dup->next;
	}
}

static void	exec_builtin_or_external(t_cmd_line *cmd, t_data *data)
{
	if (ft_strcmp(cmd->token_list->token, "cd") == 0
		|| ft_strcmp(cmd->token_list->token, "echo") == 0
		|| ft_strcmp(cmd->token_list->token, "env") == 0
		|| ft_strcmp(cmd->token_list->token, "exit") == 0
		|| ft_strcmp(cmd->token_list->token, "export") == 0
		|| ft_strcmp(cmd->token_list->token, "pwd") == 0
		|| ft_strcmp(cmd->token_list->token, "unset") == 0)
		exec_builtins(cmd, data);
	else
		exec_externals(cmd, data);
}

static void	child_process(int pipe_fd[2], t_cmd_line *cmd_list_dup, t_data *data)
{
	(void)pipe_fd;
	exec_builtin_or_external(cmd_list_dup, data);
}

static void	parent_process(int pipe_fd[2], t_cmd_line *cmd_list_dup, t_data *data)
{
	(void)pipe_fd;
	exec_builtin_or_external(cmd_list_dup, data);
}

static void	exec_commands_2(t_cmd_line *cmd_list_dup, t_data *data, int pipe_fd[2], int cmd_count)
{
	pid_t		pid;
	
	if (cmd_count == 0)
	{
		child_process(pipe_fd, cmd_list_dup, data);
		exit(0);
	}
	pid = fork();
	if (pid < 0)
	{
		exit_error(data);
	}
	if (pid == 0)
	{
		exec_commands_2(cmd_list_dup->prev, data, pipe_fd, cmd_count - 1);
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, 0);
		parent_process(pipe_fd, cmd_list_dup, data);
	}
}

void	exec_commands_1(t_cmd_line *cmd_list_dup, t_data *data)
{
	t_cmd_line	*cmd_list_dup_prev;
	int			pipe_fd[2];
	int			cmd_count;
	int			stdout_save;
	int			file;
	
	convert_env_to_array(data->env, data);
	fill_prev_cmd_node(data);
	while (cmd_list_dup != NULL)
	{
		cmd_list_dup_prev = cmd_list_dup;
		cmd_list_dup = cmd_list_dup->next;
		cmd_count++;
	}

/* 	stdout_save = dup(1);
	file = open("exec.txt", O_WRONLY | O_CREAT, 0777);
	if (file < 0)
		exit_error(data);
	if (dup2(file, 1) == -1)
		exit_error(data);
	if (pipe(pipe_fd) == -1)
		exit_error(data); */
		
	exec_commands_2(cmd_list_dup_prev, data, pipe_fd, cmd_count);
	
/* 	dup2(stdout_save, 1);
	close(file); */
}
