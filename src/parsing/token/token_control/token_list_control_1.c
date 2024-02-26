/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_control_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:48:54 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/26 22:11:28 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static char	*trim_spaces_token(char *token, t_data **data)
{
	int		spaces_counter;
	int		i;
	int		j;
	char	*new_token;

	spaces_counter = 0;
	i = 0;
	j = 0;
	while (token[i] == ' ')
	{
		if (token[i++] == ' ')
			spaces_counter++;
	}
	while (token[i])
		i++;
	while (token[--i] == ' ')
		spaces_counter++;
	ft_printf("spaces_counter: %d\n", spaces_counter);
	new_token = malloc(sizeof(char) * (i - spaces_counter + 1));
	if (!new_token)
		exit_error(*data);
	i = 0;
	while (token[i] == ' ')
		i++;
	while (j < (int)(ft_strlen(token) - spaces_counter))
		new_token[j++] = token[i++];
	new_token[j] = '\0';
	free(token);
	return (new_token);
}

static void	trim_spaces_token_list(t_cmd_line **cmd_list, t_data **data)
{
	t_cmd_line	*cmd_list_dup;
	t_token		*token_list_dup;

	cmd_list_dup = *cmd_list;
	while (cmd_list_dup)
	{
		token_list_dup = cmd_list_dup->token_list;
		while (token_list_dup)
		{
			token_list_dup->token
				= trim_spaces_token(token_list_dup->token, data);
			token_list_dup = token_list_dup->next;
		}
		cmd_list_dup = cmd_list_dup->next;
	}
}

static void	empty_token_ctrl(char *token,
	t_token **token_list_dup, t_token **token_list_dup_prev)
{
	int	i;

	i = 0;
	while (token[i] == ' ')
		i++;
	if (token[i] == '\0')
		rm_node(token_list_dup, token_list_dup_prev);
}

int	check_token_list(t_cmd_line **cmd_list, t_data **data)
{
	t_cmd_line	*cmd_list_dup;
	t_token		*token_list_dup;
	t_token		*token_list_dup_prev;
	char		*token;

	cmd_list_dup = *cmd_list;
	while (cmd_list_dup)
	{
		token_list_dup = cmd_list_dup->token_list;
		token_list_dup_prev = NULL;
		while (token_list_dup)
		{
			token = token_list_dup->token;
			empty_token_ctrl(token, &token_list_dup, &token_list_dup_prev);
			if (token_list_dup)
			{
				token_list_dup_prev = token_list_dup;
				token_list_dup = token_list_dup->next;
			}
		}
		cmd_list_dup = cmd_list_dup->next;
	}
	trim_spaces_token_list(cmd_list, data);
	return (SUCCESS);
}
