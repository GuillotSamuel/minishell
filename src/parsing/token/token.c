/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:26:18 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/10 19:47:33 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	token(char *line, t_data *data)
{
	if (line_ctrl(line, data) == 0)
	{
		ft_printf("line_ctrl passed\n");
		if (create_cmd(line, &(data->cmd_list), &data) == ERROR)
			return (ERROR);
		ft_printf("create_cmd passed\n");
		create_token(&(data->cmd_list), &data);
		ft_printf("create_token passed\n");
		if (check_token_list(&(data->cmd_list), &data) == 0)
		{
			put_type(&(data->cmd_list), &data);
			ft_printf("check_token_list passed\n");
		}
		else
		{
			ft_printf("check_token_list failed\n");
			return (ERROR);
		}
	}
	else
		return (ERROR);
	return (SUCCESS);
}
