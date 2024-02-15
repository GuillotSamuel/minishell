/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:26:18 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/15 17:18:38 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	token(char *line, t_data *data)
{
	if (line_ctrl(line) == 0)
	{
		if (create_cmd(line, &(data->cmd_list), &data) == ERROR_G)
			return (ERROR_G);
		create_token(&(data->cmd_list), &data);
		if (check_token_list(&(data->cmd_list), &data) == 0)
		{
			put_type(&(data->cmd_list), &data);
		}
		else
			return (ERROR_G);
	}
	else
		return (ERROR_G);
	return (SUCCESS);
}
