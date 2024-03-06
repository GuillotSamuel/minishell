/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:25:07 by azbk              #+#    #+#             */
/*   Updated: 2024/03/06 17:06:08 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;

char	*find_key_in_env(char *key)
{
	t_env	**env;
	t_env	*cur;

	env = ft_singletone_env();
	cur = *env;
	while (cur)
	{
		if (ft_strcmp(cur->key, key) == 0)
			return (ft_strdup(cur->value));
		cur = cur->next;
	}
	ft_putstr_fd("Error, getcwd return null, \
				and impossible to find key in env.",
					2);
	g_exit_status = 1;
	return (NULL);
}

void	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		pwd = find_key_in_env("PWD");
		if (pwd == NULL)
		{
			return ;
		}
	}
	ft_printf("%s\n", pwd);
	free(pwd);
	g_exit_status = 0;
}
