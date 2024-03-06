/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:12:02 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/06 17:13:15 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"




void	parsing(char *line, t_data *data)
{
	if (token(line, data) == ERROR_G)
		return ;
	print_token(data);
	expand_all_tokens(data);
	//ft_print_env(data->env);
	//ft_print_secret_env(data->secret_env);
	//ft_print_pwd_oldpwd(data->env);
	ft_print_pwd_oldpwd(data->secret_env);
	ft_printf("--------------------------------\n");
	ft_printf("--------------------------------\n");
	ft_pwd();
	ft_cd(data->cmd_list->args, data);
	ft_pwd();
	ft_printf("--------------------------------\n");
	ft_printf("--------------------------------\n");
	//ft_print_pwd_oldpwd(data->env);
	ft_print_pwd_oldpwd(data->secret_env);	
	//ft_print_env(data->env);
	// faire que les oldpwd et pwd soient mis a jour
	clear_lists(data);
}
