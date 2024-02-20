/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:00:21 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/20 14:06:36 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static int	create_cmd_3(char **cmd, t_cmd_line **cmd_list, char **line, int *i)
{
	char	*new_cmd_line;

	*cmd = malloc(sizeof(char) * (*i + 1));
	if (!*cmd)
		return (ERROR_G);
	(*cmd)[*i] = '\0';
	ft_strlcpy(*cmd, *line, *i);
	if (*cmd_list == NULL)
		*cmd_list = ft_stacknew_cmd(*cmd);
	else
		ft_stackaddback_cmd(cmd_list, ft_stacknew_cmd(*cmd));
	new_cmd_line = ft_remove_nchar_fromstr(*line, *i);
	free(*line);
	*line = new_cmd_line;
	*i = 0;
	return (SUCCESS);
}

static int	create_cmd_2(char *cmd, t_cmd_line **cmd_list, char *line, int i)
{
	cmd = malloc(sizeof(char) * (i + 2));
	if (!cmd)
		return (ERROR_G);
	ft_strlcpy(cmd, line, i + 1);
	if (*cmd_list == NULL)
		*cmd_list = ft_stacknew_cmd(cmd);
	else
		ft_stackaddback_cmd(cmd_list, ft_stacknew_cmd(cmd));
	return (SUCCESS);
}

int	create_cmd_1(char *line, t_cmd_line **cmd_list, t_data **data)
{
	char	*cmd;
	int		i;

	i = 0;
	cmd = NULL;
	while (line[i] != '\0')
	{
		if (cut_cmd(line) == ERROR_G)
			return (ERROR_G);
		if (end_ctrl_1(line) == 1 && i == cut_cmd(line))
		{
			if (create_cmd_3(&cmd, cmd_list, &line, &i) == ERROR_G)
				exit_error(*data);
		}
		else
		{
			i++;
		}
	}
	if (i > 0)
		if (create_cmd_2(cmd, cmd_list, line, i) == ERROR_G)
			exit_error(*data);
	return (free(line), SUCCESS);
}
