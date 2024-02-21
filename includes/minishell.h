/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:04:56 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/21 17:26:24 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* -------------------------------------------------------------------------- */
/*                                    INCLUDES                                */
/* -------------------------------------------------------------------------- */

#include "../libft/libft.h"
#include "struct.h"
#include "builtin.h"
#include "parsing.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <limits.h>

/* TESTS */
#include <stdio.h>

/* -------------------------------------------------------------------------- */
/*                                    DEFINE                                  */
/* -------------------------------------------------------------------------- */

#define SUCCESS 0
#define ERROR_G -1
#define ERROR_SYNTAX -2
#define ERROR_MALLOC -3

/* -------------------------------------------------------------------------- */
/*                                    INITIALISATION                          */
/* -------------------------------------------------------------------------- */


/* -------------------------------------------------------------------------- */
/*                                    UTILS                                   */
/* -------------------------------------------------------------------------- */

/* exit_error */
void		exit_error(t_data *data);

/* free_all_1 */
void	    clear_lists(t_data *data);
void		free_all(t_data *data);

/* free_all_2 */
void	    clear_consec_lists_3(t_data *data);

#endif