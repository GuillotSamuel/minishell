/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_ctrl_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:20:58 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/18 12:42:15 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	ft_ignore_quotes(char *l, int *i)
{
	char	quote_char;

	while (l[*i] && (l[*i] == '\"' || l[*i] == '\''))
	{
		quote_char = l[*i];
		(*i)++;
		while (l[*i] && l[*i] != quote_char)
			(*i)++;
		if (l[*i] == quote_char)
			(*i)++;
	}
}
