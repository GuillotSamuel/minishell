/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_ctrl_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:32:57 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/17 18:12:48 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

// static int	ft_strcmp_array_space_2_4(const char **cmp_arr,
// 	int j, int i, char *l)
// {
// 	if (l[i] != '\0' && l[i + 1] != '\0' && cmp_arr[j] && cmp_arr[j][0] == l[i]
// 		&& (l[i + 1] == '<' || l[i + 1] == '>') && l[i] == l[i + 1])
// 		return (-(j + 1));
// 	else if (cmp_arr[j] && cmp_arr[j][0] == l[i])
// 		return (j + 1);
// 	return (SUCCESS);
// }

// static void	ft_strcmp_array_space_2_3(char **l, int *i, int *j,
// 	const char **cmp_arr)
// {
// 	while ((*l)[*i] && (*l)[*i] == ' ')
// 		(*i)++;
// 	while (cmp_arr[*j] && cmp_arr[*j][0] != (*l)[*i])
// 		(*j)++;
// }

// static void	ft_strcmp_array_space_2_2(char **l, int *i, char *cmp_str)
// {
// 	(*i)++;
// 	if ((*l)[*i] == cmp_str[0])
// 		(*i)++;
// }

// static void	ft_strcmp_array_space_2_1(char **l, int *i, int *j,
// 	const char **cmp_arr)
// {
// 	(*i) += 2;
// 	while ((*l)[*i] && (*l)[*i] == ' ')
// 		(*i)++;
// 	while (cmp_arr[*j] && cmp_arr[*j][0] != (*l)[*i])
// 		(*j)++;
// }

// int	ft_strcmp_array_space_2(char *l, const char **cmp_arr, char *cmp_str)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	j = 0;
// 	while (l[++i])
// 	{
// 		ft_ignore_quotes(l, &i);
// 		if (l[i] != '\0' && l[i + 1] != '\0' && ft_strlen(cmp_str) == 2
// 			&& l[i] == cmp_str[0] && l[i + 1] == cmp_str[1])
// 		{
// 			if (!l[i + 2])
// 				break ;
// 			ft_strcmp_array_space_2_1(&l, &i, &j, cmp_arr);
// 			if (!l[i])
// 				break ;
// 			if (ft_strcmp_array_space_2_4(cmp_arr, j, i, l) != SUCCESS)
// 				return (ft_strcmp_array_space_2_4(cmp_arr, j, i, l));
// 			j = 0;
// 		}
// 		else if (l[i] != '\0' && l[i + 1] != '\0'
// 			&& l[i] == cmp_str[0] && ft_strlen(cmp_str) == 1)
// 		{
// 			if (!l[i + 1])
// 				break ;
// 			ft_strcmp_array_space_2_2(&l, &i, cmp_str);
// 			if (!l[i])
// 				break ;
// 			ft_strcmp_array_space_2_3(&l, &i, &j, cmp_arr);
// 			if (ft_strcmp_array_space_2_4(cmp_arr, j, i, l) != SUCCESS)
// 				return (ft_strcmp_array_space_2_4(cmp_arr, j, i, l));
// 			j = 0;
// 		}
// 	}
// 	return (SUCCESS);
// }

static int	ft_strcmp_array_space_2_4(const char **cmp_arr,
	int j, int i, char *l)
{
	if (l[i] != '\0' && l[i + 1] != '\0' && cmp_arr[j] && cmp_arr[j][0] == l[i]
		&& (l[i + 1] == '<' || l[i + 1] == '>') && l[i] == l[i + 1])
		return (-(j + 1));
	else if (cmp_arr[j] && cmp_arr[j][0] == l[i])
		return (j + 1);
	return (SUCCESS);
}

static void	ft_strcmp_array_space_2_3(char **l, int *i, int *j,
	const char **cmp_arr)
{
	while ((*l)[*i] && (*l)[*i] == ' ')
		(*i)++;
	while (cmp_arr[*j] && cmp_arr[*j][0] != (*l)[*i])
		(*j)++;
}

static void	ft_strcmp_array_space_2_2(char **l, int *i, char *cmp_str)
{
	(*i)++;
	if ((*l)[*i] == cmp_str[0])
		(*i)++;
}

static void	ft_strcmp_array_space_2_1(char **l, int *i, int *j,
	const char **cmp_arr)
{
	(*i) += 2;
	while ((*l)[*i] && (*l)[*i] == ' ')
		(*i)++;
	while (cmp_arr[*j] && cmp_arr[*j][0] != (*l)[*i])
		(*j)++;
}

/*
	This function is used to compare the following string cmp_str 
	(if cmp_str exists in str l) with the array cmp_arr
 */
int	ft_strcmp_array_space_2(char *l, const char **cmp_arr, char *cmp_str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (l[++i])
	{
		ft_ignore_quotes(l, &i);
		if (l[i] != '\0' && l[i + 1] != '\0' && ft_strlen(cmp_str) == 2
			&& l[i] == cmp_str[0] && l[i + 1] == cmp_str[1])
		{
			if (!l[i + 2])
				break ;
			ft_strcmp_array_space_2_1(&l, &i, &j, cmp_arr);
			if (!l[i])
				break ;
			if (ft_strcmp_array_space_2_4(cmp_arr, j, i, l) != SUCCESS)
				return (ft_strcmp_array_space_2_4(cmp_arr, j, i, l));
			j = 0;
		}
		else if (l[i] != '\0' && l[i + 1] != '\0'
			&& l[i] == cmp_str[0] && ft_strlen(cmp_str) == 1)
		{
			if (!l[i + 1])
				break ;
			ft_strcmp_array_space_2_2(&l, &i, cmp_str);
			if (!l[i])
				break ;
			ft_strcmp_array_space_2_3(&l, &i, &j, cmp_arr);
			if (ft_strcmp_array_space_2_4(cmp_arr, j, i, l) != SUCCESS)
				return (ft_strcmp_array_space_2_4(cmp_arr, j, i, l));
			j = 0;
		}
	}
	return (SUCCESS);
}
