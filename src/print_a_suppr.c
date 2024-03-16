/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_a_suppr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:33:02 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/16 20:41:56 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TO DELETE */
#include "../includes/minishell.h"

void	ft_print_pwd_oldpwd(t_env **env)
{
	t_env	*cur;

	cur = *env;
	while (cur)
	{
		if (strcmp(cur->key, "PWD") == 0)
			ft_printf("ENV PWD = %s\n", cur->value);
		if (strcmp(cur->key, "OLDPWD") == 0)
			ft_printf("ENV OLDPWD = %s\n", cur->value);
		cur = cur->next;
	}
}

void	print_token(t_data *data)
{
	t_cmd_line	*command;
	t_token		*current_token;
	int			i;
	int			j;

	i = 0;
	j = 1;
	command = data->cmd_list;
	while (command)
	{
		printf("\ncommande -> %d\n", j++);
		current_token = command->token_list;
		while (current_token)
		{
			printf("token[%d] = %s\n", ++i, current_token->token);
			printf("Type = %d\n", current_token->type);
			current_token = current_token->next;
		}
		command = command->next;
	}
	void print_token(t_data *data);
}
