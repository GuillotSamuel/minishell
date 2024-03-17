/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:25:45 by azbk              #+#    #+#             */
/*   Updated: 2024/03/17 17:41:46 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init_data(t_data **data, char **envp)
{
	*data = malloc(sizeof(t_data));
	if (!(*data))
		return (ERROR_G);
	(*data)->cmd_list = NULL;
	(*data)->env_array = NULL;
	(*data)->pipes_fd = NULL;
	if (ft_init_lst_env((const char **)envp) == ERROR)
		return (ERROR_G);
	(*data)->env = ft_singletone_env();
	(*data)->secret_env = dup_secret_env((*data)->env);
	if ((*data)->secret_env == MALLOC_ERROR)
	{
		free(*data);
		ft_free_env_singletone((*data)->env);
		return (ERROR_G);
	}
	return (SUCCESS);
}
