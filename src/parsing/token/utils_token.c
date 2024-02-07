/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:58:17 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/07 19:58:31 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_remove_nchar_fromstr(char *cmd_line, int n)
{
	int cmd_line_len;
	char *str;
	int i;

	i = 0;
	cmd_line_len = ft_strlen(cmd_line);
	str = malloc(sizeof(char) * (cmd_line_len - n + 1));
	if (!str)
		return (NULL);
	while (cmd_line[n + i])
	{
		str[i] = cmd_line[n + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	end_ctrl(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (0);// A REVOIR
		}
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"' && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (0);// A REVOIR
		}
		if (str[i] == '|')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp_array_space(const char *str, char * const *array)
{
	size_t i;
	size_t j;
	size_t k;

	j = 0;
	while (array[j])
	{
		i = 0;
		while (str[i] == ' ')
		i++;
		k = 0;
		while (array[j][k] == ' ')
			k++;
		while (str[i] && array[j][k] && str[i] == array[j][k])
		{
			i++;
			k++;
		}
		if (str[i] == array[j][k])
			return (0);
		j++;
	}
	return (1);
}

int ft_strcmp_space(const char *s1, const char *s2)
{
	size_t i;
	size_t j;

	i = 0;
	while (s1[i] == ' ')
		i++;
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	return (1);
}

int	ft_charcmp_array(char c, char **array)
{
	size_t i;

	i = 0;
	while (array[i])
	{
		if (c == array[i][0])
			return (0);
		i++;
	}
	return (1);
}
