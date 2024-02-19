/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:42:47 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/19 13:56:20 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	put_type_3(t_token **token_list_dup1, t_token **token_list_dup2,
	t_cmd_line **cmd_list_dup)
{
	*token_list_dup1 = (*cmd_list_dup)->token_list;
	*token_list_dup2 = NULL;
}

void	put_type_4(t_token **token_list_dup1, t_token **token_list_dup2)
{
	*token_list_dup2 = *token_list_dup1;
	*token_list_dup1 = (*token_list_dup1)->next;
}
