/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:13:05 by sguillot          #+#    #+#             */
/*   Updated: 2024/03/20 15:14:49 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum type
{
	NON,
	ARG,
	BUILTIN,
	OPEN_FILE,
	HERE_DOC,
	LIMITOR,
	CREAT_FILE,
	WRITE_FILE,
	FILE_IN,
	FILE_OUT,
	FILE_OUT_OVER,
	ENDS
}						t_enum_type;

typedef struct s_token
{
	char				*token;
	t_enum_type			type;
	struct s_token		*next;
}						t_token;

typedef struct s_redir
{
	int					fd_in;
	int					fd_out;
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
	char				*line_free;
	struct s_env		**env;
	struct s_env		**secret_env;
	int					**pipes_fd;
	int					*pids;
	char				**env_array;
}						t_data;

#endif