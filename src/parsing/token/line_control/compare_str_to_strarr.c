/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_str_to_strarr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:07:05 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/18 21:44:07 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static void	loop_ca(const char **ca, char *l, int i, int *j)
{
	*j = 0;
	while (ca[*j] && ca[*j][0] != l[i])
		(*j)++;
}

static void	loop_l(char *l, int *i)
{
	while (l[*i] && l[*i] == ' ')
		(*i)++;
}

static int	ft_forbiden_char_double(char *l, int *i, char *s)
{
	loop_l(l, i);
	if (l[*i] && ft_strlen(s) == 2 && l[*i + 1]
		&& l[*i] == s[0] && l[*i + 1] == s[1])
		return (2);
	else
		return (0);
}

int	ft_strcmp_array_space_3(char *l, const char **ca, char *s)
{
	int	i;
	int	j;

	i = -1;
	while (l[++i])
	{
		if (l[i] == '\'' || l[i] == '\"')
			ft_ignore_quotes(l, &i);
		if (!l[i])
			return (SUCCESS);
		loop_ca(ca, l, i, &j);
		if (ca[j] && ca[j][0] == l[i])
		{
			if (!l[++i])
				break ;
			if (((ft_strlen(s) == 1 && l[i] != s[0]) || ft_strlen(s) == 2))
			{
				if (ft_forbiden_char_double(l, &i, s) == 2)
					return (2);
				else if (ca[j] && ft_strlen(s) == 1 && l[i] && l[i] == s[0])
					return (1);
			}
		}
	}
	return (SUCCESS);
}
