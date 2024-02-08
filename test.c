/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:36:34 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/08 13:30:58 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_cmp
{
	char	*chevron_list[4];
	char	*builtin_list[7];
	char	*start_end_ctrl[1];
	char const	**consec_list_1;
	char const	**consec_list_2;
	char const	**consec_list_3;
	char const	**consec_list_4;
	char const	**consec_list_5;
	char const	**consec_list_6;
	char const	**consec_list_7;
	char const	**consec_list_8;
}	t_cmp;

/* t_cmp cmp = {
    .chevron_list = {"chevron1", "chevron2", "chevron3", "chevron4"},
    .builtin_list = {"builtin1", "builtin2", "builtin3", "builtin4", "builtin5", "builtin6", "builtin7"},
    .start_end_ctrl = {"ctrl"},
    .consec_list_1 = (const char *[]){"item1", "item2", NULL},
    .consec_list_2 = (const char *[]){"item1", "item2", NULL},
    .consec_list_3 = (const char *[]){"item1", "item2", NULL},
    .consec_list_4 = (const char *[]){"item1", "item2", NULL},
    .consec_list_5 = (const char *[]){"item1", "item2", NULL},
    .consec_list_6 = (const char *[]){"item1", "item2", NULL},
    .consec_list_7 = (const char *[]){"?", "*", "#", ";", NULL},
    .consec_list_8 = (const char *[]){"?", "*", "|", "&", ";", NULL}
}; */
