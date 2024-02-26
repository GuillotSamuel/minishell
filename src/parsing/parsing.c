/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:12:02 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/26 16:46:08 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	parsing(char *line, t_data *data)
{
	if (token(line, data) == ERROR_G)
		return ;
	expand_all_tokens(data);
	// a suppr
	print_token(data);
	clear_lists(data);
}
