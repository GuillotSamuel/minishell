/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_ctrl_1superior.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:52:35 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/18 21:16:42 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	control_s1(char *line)
{
	const char	*cmp1[] = {"#", "<", "(", ")", ";", NULL};

	if (compare_one_doublechar_to_str('>', line, cmp1) != SUCCESS)
	{
		ft_printf("s1 1\n");
		ft_printf("bash: parse error near `%s%s'\n",
			cmp1[compare_one_doublechar_to_str('>', line, cmp1) - 1],
			cmp1[compare_one_doublechar_to_str('>', line, cmp1) - 1]);
		return (ERROR_SYNTAX);
	}
	else if (compare_one_char_to_str('>', line, cmp1) != SUCCESS)
	{
		ft_printf("s1 2\n");
		ft_printf("bash: parse error near `%s'\n",
			cmp1[compare_one_char_to_str('>', line, cmp1) - 1]);
		return (ERROR_SYNTAX);
	}
	if (ft_space_ctrl_1(line, '>', '&') == ERROR_SYNTAX)
		return (ft_printf("bash: syntax error near unexpected token `&'\n"),
			ERROR_SYNTAX);
	if (ft_space_ctrl_1(line, '>', '|') == ERROR_SYNTAX)
		return (ft_printf("bash: syntax error near unexpected token `|'\n"),
			ERROR_SYNTAX);
	return (SUCCESS);
}

int	control_s2(char *line)
{
	const char	*cmp1[] = {"<", "(", ")", NULL};

	if (ft_strcmp_array_space_3(line, cmp1, ">") == 1)
	{
		ft_printf("s2 1\n");
		ft_printf("bash: parse error near `>'\n");
		return (ERROR_SYNTAX);
	}
	return (SUCCESS);
}
