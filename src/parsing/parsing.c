/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:12:02 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/08 18:34:46 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parsing(char *line, t_data *data)
{
	if (token(line, data) == ERROR_G)
		return (clear_lists(data));
	if (expand_all_tokens(data) == ERROR)
		return (clear_lists(data));
	start_exec(data);
	clear_lists(data);
}
