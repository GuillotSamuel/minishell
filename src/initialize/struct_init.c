/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:00:01 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/09 17:08:17 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_cmp	*consec_list_init(t_cmp *cmp)
{
	cmp->consec_list_1 = (const char *[]){"#", "<<", "<", ">>", ">", "|", "&", "(", ")", ";", NULL};
	cmp->consec_list_2 = (const char *[]){"?", "*", NULL};
	cmp->consec_list_3 = (const char *[]){"#", "<<", "<", ">>", ">", "(", ")", ";", NULL};
	cmp->consec_list_4 = (const char *[]){"#", "<<", "<", ">>", ">", "|", "&", ")", ";", NULL};
	cmp->consec_list_5 = (const char *[]){"<<", "<", ">>", ">", "(", ")", NULL};
	cmp->consec_list_6 = (const char *[]){"?", "*", "|", NULL};
	cmp->consec_list_7 = (const char *[]){"?", "*", "#", ";", NULL},
	cmp->consec_list_8 = (const char *[]){"?", "*", "|", "&", ";", NULL};
	cmp->consec_list_9 = (const char *[]){"#", ";", NULL};
	cmp->consec_list_10 = (const char *[]){"&", NULL};
	cmp->consec_list_11 = (const char *[]){"|", NULL};
	cmp->consec_list_12 = (const char *[]){"(", NULL};
	cmp->consec_list_13 = (const char *[]){"#", NULL};
	return (cmp);
}

static void	initialize_t_cmp(t_data **data)
{
	t_cmp	*cmp;

	cmp = malloc(sizeof(t_cmp));
	if (!cmp)
		exit_error (*data);
	(*data)->cmp = cmp;
	cmp->chevron_list = (const char *[]){">", ">>", "<", "<<", NULL};
	cmp->builtin_list = (const char *[]){"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};
	cmp->start_end_ctrl = (const char *[]){"|", NULL};
	consec_list_init((*data)->cmp);
}

void	init_struct(t_data *data)
{
	data->cmd_list = malloc(sizeof(t_cmd_line));
	if (!data->cmd_list)
		exit_error(data);
	data->cmd_list = NULL;
    initialize_t_cmp(&data);
}
