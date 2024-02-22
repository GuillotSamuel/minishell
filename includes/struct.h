/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:13:05 by sguillot          #+#    #+#             */
/*   Updated: 2024/02/22 17:28:13 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H


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
	int				jump;
	enum_type		type;
	struct s_token	*next;
} t_token;

typedef struct s_cmd_line
{
	char				*cmd;
	t_token				*token_list;
	char				**args;
	struct s_cmd_line	*next;
} t_cmd_line;

typedef struct s_env
{
	char				*str;
	char				*key;
	char				*value;
	struct s_env		*next;
} t_env;

typedef struct s_data
{
	t_cmd_line	*cmd_list;
	t_env		**env;
	t_env		**dup_secret_env;
} t_data;

#endif