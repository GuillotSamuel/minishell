/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_ctrl_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:32:57 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/21 13:31:06 by emauduit         ###   ########.fr       */
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

int	compare_one_char_to_str(char needle, char *h,
	const char **forbiden_consec)
{
	int	i;
	int	j;

	i = -1;
	while (h[++i] != '\0')
	{
		j = -1;
		if (h[i] == '\'' || h[i] == '\"')
			ft_ignore_quotes(h, &i);
		if (h[i] == '\0')
			return (SUCCESS);
		if (h[i] == needle && h[i] != '\0')
		{
			i++;
			while (h[i] != '\0' && (h[i] == ' '
					|| h[i] == '\t' || h[i] == '\n'))
				i++;
			while (forbiden_consec[++j] != NULL)
				if (h[i] != '\0' && h[i] == forbiden_consec[j][0])
					return (j + 1);
		}
	}
	return (SUCCESS);
}

int	compare_two_chars_to_str(char n, char *h,
	const char **forbiden_consec)
{
	int	i;
	int	j;

	i = -1;
	while (h[++i] != '\0')
	{
		j = -1;
		if (h[i] == '\'' || h[i] == '\"')
			ft_ignore_quotes(h, &i);
		if (h[i] == '\0' || h[i + 1] == '\0')
			return (SUCCESS);
		if (h[i] == n && h[i + 1] == n)
		{
			i += 2;
			while (h[i] != '\0' && (h[i] == ' '
					|| h[i] == '\t' || h[i] == '\n'))
				i++;
			while (forbiden_consec[++j] != NULL)
				if (h[i] != '\0' && h[i] == forbiden_consec[j][0])
					return (j + 1);
		}
	}
	return (SUCCESS);
}

int	compare_one_doublechar_to_str(char needle, char *h,
	const char **forbiden_consec)
{
	int	i;
	int	j;

	i = -1;
	while (h[++i] != '\0')
	{
		j = -1;
		if (h[i] == '\'' || h[i] == '\"')
			ft_ignore_quotes(h, &i);
		if (h[i] == '\0')
			return (SUCCESS);
		if (h[i] == needle)
		{
			i++;
			while (h[i] != '\0' && (h[i] == ' '
					|| h[i] == '\t' || h[i] == '\n'))
				i++;
			while (forbiden_consec[++j] != NULL)
				if (h[i] != '\0' && h[i] == forbiden_consec[j][0]
					&& h[i + 1] != '\0' && h[i + 1] == forbiden_consec[j][0])
					return (j + 1);
		}
	}
	return (SUCCESS);
}

int	compare_two_doublechars_to_str(char needle,
	char *h, const char **forbiden_c)
{
	int	i;
	int	j;

	i = -1;
	while (h[++i] != '\0')
	{
		j = -1;
		if (h[i] == '\'' || h[i] == '\"')
			ft_ignore_quotes(h, &i);
		if (h[i] == '\0' || h[i + 1] == '\0')
			return (SUCCESS);
		if (h[i] == needle && h[i + 1] == needle)
		{
			i += 2;
			while (h[i] && (h[i] == ' ' || h[i] == '\t' || h[i] == '\n'))
				i++;
			while (forbiden_c[++j] != NULL)
				if (h[i] != '\0' && h[i] == forbiden_c[j][0]
					&& h[i + 1] != '\0' && h[i + 1] == forbiden_c[j][0])
					return (j + 1);
		}
	}
	return (SUCCESS);
}
