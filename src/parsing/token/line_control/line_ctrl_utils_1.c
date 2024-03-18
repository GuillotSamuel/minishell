/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_ctrl_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:32:57 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/18 21:30:27 by sguillot         ###   ########.fr       */
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

int	compare_one_char_to_str(char needle, char *haystack,
	const char **forbiden_consec)
{
	int	i;
	int	j;

	i = -1;
	while (haystack[++i] != '\0')
	{
		j = -1;
		if (haystack[i] == '\'' || haystack[i] == '\"')
		{
			ft_ignore_quotes(haystack, &i);
			if (haystack[i] == '\0')
				return (SUCCESS);
		}
		else if (haystack[i] == needle && haystack[i + 1] != '\0')
		{
			while (forbiden_consec[++j] != NULL)
			{
				if (haystack[i + 1] == forbiden_consec[j][0])
					return (j + 1);
			}
		}
	}
	return (SUCCESS);
}

int	compare_two_chars_to_str(char needle, char *haystack,
	const char **forbiden_consec)
{
	int	i;
	int	j;

	i = -1;
	while (haystack[++i] != '\0')
	{
		j = -1;
		if (haystack[i] == '\'' || haystack[i] == '\"')
			ft_ignore_quotes(haystack, &i);
		if (haystack[i] == '\0')
			return (SUCCESS);
		if (haystack[i] == needle)
		{
			if (haystack[++i] != '\0' && haystack[i] == needle
				&& haystack[i + 1] != '\0')
			{
				while (forbiden_consec[++j] != NULL)
				{
					if (haystack[i + 1] == forbiden_consec[j][0])
						return (j + 1);
				}
			}
		}
	}
	return (SUCCESS);
}

int	compare_one_doublechar_to_str(char needle, char *haystack,
	const char **forbiden_consec)
{
	int	i;
	int	j;

	i = -1;
	while (haystack[++i] != '\0')
	{
		j = -1;
		if (haystack[i] == '\'' || haystack[i] == '\"')
			ft_ignore_quotes(haystack, &i);
		if (haystack[i] == '\0')
			return (SUCCESS);
		if (haystack[i] == needle && haystack[i + 1] != '\0'
			&& haystack[i + 1] == needle)
		{
			if (haystack[i + 2] != '\0')
			{
				while (forbiden_consec[++j] != NULL)
					if (haystack[i + 1] == forbiden_consec[j][0]
						&& haystack[i + 2] == forbiden_consec[j][1])
						return (j + 1);
			}
		}
	}
	return (SUCCESS);
}

int	compare_two_doublechars_to_str(char needle,
	char *haystack, const char **forbiden_c)
{
	int	i;
	int	j;

	i = -1;
	while (haystack[++i] != '\0')
	{
		j = -1;
		if (haystack[i] == '\'' || haystack[i] == '\"')
			ft_ignore_quotes(haystack, &i);
		if (haystack[i] == '\0')
			return (SUCCESS);
		if (haystack[i] == needle && haystack[i + 1] != '\0'
			&& haystack[i + 1] == needle)
		{
			i += 2;
			while (forbiden_c[++j] != NULL)
			{
				if (haystack[i] && haystack[i] == forbiden_c[j][0]
					&& haystack[i + 1] && haystack[i + 1] == forbiden_c[j][0])
					return (j + 1);
			}
		}
	}
	return (SUCCESS);
}
