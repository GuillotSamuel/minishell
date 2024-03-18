/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_ctrl_2superior.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:52:35 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/18 21:47:53 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	control_ss1(char *line)
{
	const char	*cmp1[] = {"#", "<", ">", "|", "&", "(", ")", ";", NULL};

	if (compare_two_doublechars_to_str('>', line, cmp1) != SUCCESS)
	{
		ft_printf("bash: parse error near `%s%s'\n",
			cmp1[compare_two_doublechars_to_str('>', line, cmp1) - 1],
			cmp1[compare_two_doublechars_to_str('>', line, cmp1) - 1]);
		return (ERROR_SYNTAX);
	}
	else if (compare_two_chars_to_str('>', line, cmp1) != SUCCESS)
	{
		ft_printf("bash: parse error near `%s'\n",
			cmp1[compare_two_chars_to_str('>', line, cmp1) - 1]);
		return (ERROR_SYNTAX);
	}
	return (SUCCESS);
}

int	control_ss2(char *line)
{
	const char	*cmp1[] = {"<", ">", "(", ")", NULL};

	if (ft_strcmp_array_space_3(line, cmp1, ">>") == 2)
	{
		ft_printf("bash: parse error near `>>'\n");
		return (ERROR_SYNTAX);
	}
	return (SUCCESS);
}
