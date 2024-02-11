/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:54:54 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/11 22:08:43 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_token	*ft_stacknew_token(char *content)
{
	t_token *new_element;

	new_element = (t_token *)malloc(sizeof(t_token));
	if (!new_element)
		return (NULL);
	new_element->token = content;
	new_element->next = NULL;
	return (new_element);
}

void	ft_stackaddback_token(t_token **lst, t_token *new)
{
	t_token *tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void	create_token(t_cmd_line **cmd_list, t_data **data)
{
	t_cmd_line	*current_cmd;
	char		*token;
	char		*token_dup;
	int			i;

	current_cmd = *cmd_list;
	while (current_cmd)
	{
		i = 0;
		token_dup = ft_strdup(current_cmd->cmd);
		while (token_dup[i] != '\0')
		{
			ft_printf("test de la loop\n");
			if (i == cut_token(token_dup, (*data)))
			{
				token = malloc(sizeof(char) * (i + 1));
				if (!token)
					exit_error(*data);
				token[i] = '\0';
				ft_strlcpy(token, token_dup, i + 1);
				if (current_cmd->token_list == NULL)
				{
					current_cmd->token_list = ft_stacknew_token(token);
					ft_printf("test 1\n");
				}
				else
				{
					ft_stackaddback_token(&(current_cmd->token_list), ft_stacknew_token(token));
					ft_printf("test 2\n");
				}
				token_dup = ft_remove_nchar_fromstr(token_dup, i + 1);
				i = 0;
			}
			else
				i++;
		}
		if (i > 0)
		{
			ft_printf("test du if\n");
			token = malloc(sizeof(char) * (i + 2));
			if (!token)
				exit_error(*data);
			ft_printf("test du malloc du if \n");
			ft_strlcpy(token, token_dup, i + 1);
			ft_printf("test du strlcpy du if \n");
			if (current_cmd->token_list != NULL)
				ft_printf("test de current_cmd->token_list : %s\n", current_cmd->token_list->token);
			if (current_cmd->token_list == NULL)
			{
				ft_printf("test du if 2 du if\n");
				current_cmd->token_list = ft_stacknew_token(token);
				ft_printf("test 3\n");
			}
			else
			{
				ft_printf("test du else du if\n");
				ft_stackaddback_token(&(current_cmd->token_list), ft_stacknew_token(token));
				ft_printf("test 4\n");
			}
		}
		ft_printf("test du while principal\n");
		free(token_dup);
		current_cmd = current_cmd->next;
	}
}
