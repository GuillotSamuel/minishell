/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_str_to_strarr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:07:05 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/18 12:26:22 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static void	loop_ca(const char **ca, char *l, int i, int *j)
{
	while (ca[*j] && ca[*j][0] != l[i])
		(*j)++;
}

static void	loop_l(char *l, int *i)
{
	while (l[*i] && l[*i] == ' ')
		(*i)++;
}

int	ft_strcmp_array_space_3(char *l, const char **ca, char *cs)
{
	int	i;
	int	j;

	i = -1;
	while (l[++i])
	{
		j = 0;
		loop_ca(ca, l, i, &j);
		if (ca[j] && ca[j][0] == l[i])
		{
			if (!l[++i])
				break ;
			if (l[i] && ((ft_strlen(cs) == 1 && l[i] != cs[0])
					|| ft_strlen(cs) == 2))
			{
				loop_l(l, &i);
				if (l[i] && ft_strlen(cs) == 2 && l[i + 1]
					&& l[i] == cs[0] && l[i + 1] == cs[1])
					return (2);
				else if (ca[j] && ft_strlen(cs) == 1 && l[i] && l[i] == cs[0])
					return (1);
			}
		}
	}
	return (SUCCESS);
}
