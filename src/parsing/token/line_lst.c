/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:00:21 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/09 15:42:24 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_cmd_line	*ft_stacknew_cmd(char *content)
{
	t_cmd_line *new_element;

	new_element = (t_cmd_line *)malloc(sizeof(t_cmd_line));
	if (!new_element)
		return (NULL);
	new_element->cmd = content;
	new_element->next = NULL;
	return (new_element);
}

void	ft_stackaddback_cmd(t_cmd_line **line, t_cmd_line *new)
{
	t_cmd_line *tmp;

	if (*line == NULL)
		*line = new;
	else
	{
		tmp = *line;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int	create_cmd(char *line, t_cmd_line **cmd_list, t_data **data)
{
	char	*new_cmd_line;
	char	*cmd;
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[0] == '|')
			return (two_pipes_error(*data), -1);
		if (end_ctrl(line) == 1 && i == cut_cmd(line, (*data)))
		{
			cmd = malloc(sizeof(char) * (i + 1));
			if (!cmd)
				exit_error(*data);
			cmd[i] = '\0';
			ft_strlcpy(cmd, line, i);
			if ((*cmd_list)->cmd == NULL)
				*cmd_list = ft_stacknew_cmd(cmd);
			else
				ft_stackaddback_cmd(cmd_list, ft_stacknew_cmd(cmd));
			new_cmd_line = ft_remove_nchar_fromstr(line, i);
			free(line);
			line = new_cmd_line;
			i = 0;
		}
		else
			i++;
	}
	if (i > 0)
	{
		cmd = malloc(sizeof(char) * (i + 2));
		if (!cmd)
			exit_error(*data);
		ft_strlcpy(cmd, line, i + 1);
		if ((*cmd_list)->cmd == NULL)
			*cmd_list = ft_stacknew_cmd(cmd);
		else
			ft_stackaddback_cmd(cmd_list, ft_stacknew_cmd(cmd));
	}
	free(line);
	return (0);
}
