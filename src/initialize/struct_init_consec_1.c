/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init_consec_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:05:02 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/07 19:09:32 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_cmp	*consec_list_init_4(t_cmp *cmp)
{
	cmp->consec_list_4[0] = "?";
	cmp->consec_list_4[1] = "*";
	return (cmp);
}

static t_cmp	*consec_list_init_3(t_cmp *cmp)
{
	cmp->consec_list_3[0] = "<<";
	cmp->consec_list_3[1] = "<";
	cmp->consec_list_3[2] = ">>";
	cmp->consec_list_3[3] = ">";
	cmp->consec_list_3[4] = "(";
	cmp->consec_list_3[5] = ")";
	return (cmp);
}

static t_cmp	*consec_list_init_2(t_cmp *cmp)
{
	cmp->consec_list_2[0] = "#";
	cmp->consec_list_2[1] = "<<";
	cmp->consec_list_2[2] = "<";
	cmp->consec_list_2[3] = ">>";
	cmp->consec_list_2[4] = ">";
	cmp->consec_list_2[5] = "(";
	cmp->consec_list_2[6] = ")";
	cmp->consec_list_2[7] = ";";
	return (cmp);
}

static t_cmp	*consec_list_init_1(t_cmp *cmp)
{
	cmp->consec_list_1[0] = "#";
	cmp->consec_list_1[1] = "<<";
	cmp->consec_list_1[2] = "<";
	cmp->consec_list_1[3] = ">>";
	cmp->consec_list_1[4] = ">";
	cmp->consec_list_1[5] = "|";
	cmp->consec_list_1[6] = "&";
	cmp->consec_list_1[7] = "(";
	cmp->consec_list_1[8] = ")";
	cmp->consec_list_1[9] = ";";
	return (cmp);
}

t_cmp	*consec_list_init(t_cmp *cmp)
{
	consec_list_init_1(cmp);
	consec_list_init_2(cmp);
	consec_list_init_3(cmp);
	consec_list_init_4(cmp);
	consec_list_init_5(cmp);
	consec_list_init_6(cmp);
	consec_list_init_7(cmp);
	consec_list_init_8(cmp);
    return (cmp);
}