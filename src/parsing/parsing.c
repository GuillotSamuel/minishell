/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:12:02 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/21 13:20:04 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parsing(char *line, t_data *data)
{
	if (token(line, data) == ERROR_G)
	{
		free(data->line_free);
		data->line_free = NULL;
		return (ERROR_G);
	}
	free(data->line_free);
	data->line_free = NULL;
	if (expand_all_tokens(data) == ERROR)
		return (ERROR_G);
	return (SUCCESS);
}
