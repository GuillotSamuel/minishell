/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:33:42 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/14 17:28:32 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	convert_env_to_array(t_env **env, t_data *data)
{
	char	**env_array;
	int		i;
	t_env	*env_dup;

	i = 0;
	env_dup = *env;
	while (env_dup != NULL)
	{
		i++;
		env_dup = env_dup->next;
	}
	env_array = malloc(sizeof(char *) * (i + 1));
	if (env_array == NULL)
		exit_error(data);
	env_dup = *env;
	i = 0;
	while (env_dup != NULL)
	{
		env_array[i] = ft_strjoin(env_dup->key, env_dup->value);
		i++;
		env_dup = env_dup->next;
	}
	env_array[i] = NULL;
	data->env_array = env_array;
}

int	ft_execve_exec(char *path, t_cmd_line *cmd_list_dup, t_data *data)
{
	convert_env_to_array(data->env, data);
	if (execve(path, cmd_list_dup->args, data->env_array) == -1)
	{
		return (FAIL);
	}
	return (SUCCESS);
}
