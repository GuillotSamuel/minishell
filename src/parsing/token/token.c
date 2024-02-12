/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:26:18 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/12 12:24:47 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	token(char *line, t_data *data)
{
	if (line_ctrl(line) == 0)
	{
		if (create_cmd(line, &(data->cmd_list), &data) == ERROR)
			return (ERROR);
		create_token(&(data->cmd_list), &data);
		if (check_token_list(&(data->cmd_list), &data) == 0)
		{
			put_type(&(data->cmd_list), &data);
		}
		else
			return (ERROR);
	}
	else
		return (ERROR);
	return (SUCCESS);
}
