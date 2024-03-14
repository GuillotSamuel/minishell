/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:13:05 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/14 12:20:06 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum type
{
	NON,
	ARG,           // word
	BUILTIN,       // builtin
	OPEN_FILE,     //  word following '<'
	HERE_DOC,      // word == '<<'
	LIMITOR,       // word following '<<'
	CREAT_FILE,    // word following '>'
	WRITE_FILE,    // word following '>>'
	FILE_IN,       // word == '<'
	FILE_OUT,      // word == '>'
	FILE_OUT_OVER, // word == '>>'
	ENDS
}						enum_type;

typedef struct s_token
{
	char				*token;
	enum_type			type;
	struct s_token		*next;
}						t_token;

typedef struct s_redir
{								// echo salut > file | wc -l
	int					fd_in; // 0
	int					fd_out; // 
	char				*file_here_doc;
}						t_redir;

typedef struct s_cmd_line
{
	char				*cmd;
	t_token				*token_list;
	struct s_redir		*redir;
	char				**args;
	struct s_cmd_line	*next;
}						t_cmd_line;

typedef struct s_env
{
	char				*str;
	char				*key;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef struct s_data
{
	t_cmd_line			*cmd_list;
	pid_t				*pid;
	struct s_env		**env;
	struct s_env		**secret_env;
}						t_data;

#endif