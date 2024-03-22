/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_assign_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:00:21 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/20 15:15:46 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static int	create_cmd_3(char **cmd, t_cmd_line **cmd_list, int *i,
		t_data *data)
{
	*cmd = malloc(sizeof(char) * (*i + 1));
	if (!*cmd)
		return (ERROR_G);
	*cmd = ft_memset(*cmd, '\0', *i + 1);
	ft_strlcpy(*cmd, data->line_free, *i);
	if (*cmd_list == NULL)
		*cmd_list = ft_stacknew_cmd(*cmd);
	else
		ft_stackaddback_cmd(cmd_list, ft_stacknew_cmd(*cmd));
	ft_remove_nchar_from_str(data->line_free, *i, data);
	*i = 0;
	return (SUCCESS);
}

static int	create_cmd_2(char *cmd, t_cmd_line **cmd_list, char *line, int i)
{
	cmd = malloc(sizeof(char) * (i + 2));
	if (!cmd)
		return (ERROR_G);
	cmd = ft_memset(cmd, '\0', i + 2);
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
	(*data)->line_free = line;
	while ((*data)->line_free[i] != '\0')
	{
		if (cut_cmd((*data)->line_free) == ERROR_G)
			return (ERROR_G);
		if (end_ctrl_1((*data)->line_free) == 1
			&& i == cut_cmd((*data)->line_free))
		{
			if (create_cmd_3(&cmd, cmd_list, &i, *data) == ERROR_G)
				exit_error(*data);
		}
		else
			i++;
	}
	if (i > 0)
		if (create_cmd_2(cmd, cmd_list, (*data)->line_free, i) == ERROR_G)
			exit_error(*data);
	return (SUCCESS);
}
