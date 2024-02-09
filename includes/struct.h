/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:13:05 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/08 19:17:18 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cmp
{
	char const	**chevron_list;
	char const	**builtin_list;
	char const	**start_end_ctrl;
	char const	**consec_list_1;
	char const	**consec_list_2;
	char const	**consec_list_3;
	char const	**consec_list_4;
	char const	**consec_list_5;
	char const	**consec_list_6;
	char const	**consec_list_7;
	char const	**consec_list_8;
    char const  **consec_list_9;
    char const  **consec_list_10;
    char const  **consec_list_11;
    char const  **consec_list_12;
    char const  **consec_list_13;
}	t_cmp;

typedef enum type
{
    NON,
    ARG, // word 
    BUILTIN, // builtin
    OPEN_FILE, //  word following '<'
    HERE_DOC, // word == '<<'
    LIMITOR, // word following '<<'
    CREAT_FILE, // word following '>'
    WRITE_FILE, // word following '>>'
    FILE_IN, //word == '<'
    FILE_OUT, //word == '>'
    FILE_OUT_OVER, //word == '>>'
    ENDS
} enum_type;

typedef struct s_token
{
    char			*token;
    enum_type		type;
    struct s_token	*next;
} t_token;

typedef struct s_cmd_line
{
	char				*cmd;
	t_token				*token_list;
	char				**args;
	struct s_cmd_line	*next;
    char			    **env;
} t_cmd_line;

typedef struct s_data
{
	t_token		*t;
	t_cmd_line	*cmd_list;
    t_cmp		*cmp;
} t_data;

#endif