/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:13:12 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/07 18:37:35 by sguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cmp
{
    char	*chevron_list[4];
    char	*builtin_list[7];
    char    *start_end_ctrl[1];
    char    *consec_list_1[10]; // # << < >> > | & ( ) ;
    char    *consec_list_2[8]; // # << < >> > ( ) ;
    char    *consec_list_3[6]; // << < >> > ( )
    char    *consec_list_4[2]; // ? *
    char    *consec_list_5[3]; // ? * |
    char    *consec_list_6[5]; // ? * | & ;
    char    *consec_list_7[4]; // ? * # ;
    char    *consec_list_8[5]; // ? * | & ;
} t_cmp;

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