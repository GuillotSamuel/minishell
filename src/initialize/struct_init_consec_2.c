/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init_consec_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:04:59 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/07 19:06:35 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmp	*consec_list_init_8(t_cmp *cmp)
{
	cmp->consec_list_8[0] = "?";
	cmp->consec_list_8[1] = "*";
	cmp->consec_list_8[2] = "|";
	cmp->consec_list_8[3] = "&";
	cmp->consec_list_8[4] = ";";
	return (cmp);
}

t_cmp	*consec_list_init_7(t_cmp *cmp)
{
	cmp->consec_list_7[0] = "?";
	cmp->consec_list_7[1] = "*";
	cmp->consec_list_7[2] = "#";
	cmp->consec_list_7[3] = ";";
	return (cmp);
}

t_cmp	*consec_list_init_6(t_cmp *cmp)
{
	cmp->consec_list_6[0] = "?";
	cmp->consec_list_6[1] = "*";
	cmp->consec_list_6[2] = "|";
	cmp->consec_list_6[3] = "&";
	cmp->consec_list_6[4] = ";";
	return (cmp);
}

t_cmp	*consec_list_init_5(t_cmp *cmp)
{
	cmp->consec_list_5[0] = "?";
	cmp->consec_list_5[1] = "*";
	cmp->consec_list_5[2] = "|";
	return (cmp);
}
