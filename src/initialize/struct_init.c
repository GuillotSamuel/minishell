/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:00:01 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/10 19:05:23 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

	// cmp->consec_list_1 = (const char *[]){"#", "<<", "<", ">>", ">", "|", "&", "(", ")", ";", NULL};
	// cmp->consec_list_2 = (const char *[]){"?", "*", NULL};
	// cmp->consec_list_3 = (const char *[]){"#", "<<", "<", ">>", ">", "(", ")", ";", NULL};
	// cmp->consec_list_4 = (const char *[]){"#", "<<", "<", ">>", ">", "|", "&", ")", ";", NULL};
	// cmp->consec_list_5 = (const char *[]){"<<", "<", ">>", ">", "(", ")", NULL};
	// cmp->consec_list_6 = (const char *[]){"?", "*", "|", NULL};
	// cmp->consec_list_7 = (const char *[]){"?", "*", "#", ";", NULL},
	// cmp->consec_list_8 = (const char *[]){"?", "*", "|", "&", ";", NULL};
	// cmp->consec_list_9 = (const char *[]){"#", ";", NULL};
	// cmp->consec_list_10 = (const char *[]){"&", NULL};
	// cmp->consec_list_11 = (const char *[]){"|", NULL};
	// cmp->consec_list_12 = (const char *[]){"(", NULL};
	// cmp->consec_list_13 = (const char *[]){"#", NULL};
	// cmp->chevron_list = (const char *[]){">", ">>", "<", "<<", NULL};
	// cmp->builtin_list = (const char *[]){"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};
	// cmp->start_end_ctrl = (const char *[]){"|", NULL};

void	init_struct(t_data *data)
{
	data->cmd_list = malloc(sizeof(t_cmd_line));
	if (!data->cmd_list)
		exit_error(data);
	data->cmd_list = NULL;
}
