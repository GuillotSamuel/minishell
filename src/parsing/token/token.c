/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:26:18 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/09 19:24:24 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	token(char *line, t_data *data)
{
	if (line_ctrl(line, data) == 0)
	{
		if (create_cmd(line, &(data->cmd_list), &data) == -1)
			return (-1);
		ft_printf("create_cmd done\n");
		create_token(&(data->cmd_list), &data);
		ft_printf("create_token done 2\n");
		while (data->cmd_list != NULL)
		{
			while (data->cmd_list->token_list != NULL)
			{
				ft_printf("token_list:%s\n", data->cmd_list->token_list->token);
				data->cmd_list->token_list = data->cmd_list->token_list->next;
			}
						ft_printf("cmd_list:%s\n", data->cmd_list->cmd);

			data->cmd_list = data->cmd_list->next;
		}
		ft_printf("********************************************************************\n");
		
		if (check_token_list(&(data->cmd_list), &data) == 0)
		{
			put_type(&(data->cmd_list), &data);
			ft_printf("put_type\n");
		}
		else
		{
			return (-1);
			ft_printf("check_token_list failed\n");
		}
	}
	else
		return (-1);
	return (0);
}
