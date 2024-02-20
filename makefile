# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguillot <sguillot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 16:12:37 by azbk              #+#    #+#              #
#    Updated: 2024/02/20 14:58:53 by sguillot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                COMPILATION                                   #
################################################################################

NAME = minishell

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
CIFLAGS	= -Iincludes -I$(LIB_DIR)/includes
CCLIED	= -L$(LIB_DIR) -lft -lreadline
MAKEFLAGS += --no-print-directory


LIBFT = ./libft/libft.a
SRC_DIR = ./src

################################################################################
#                                  SOURCES                                     #
################################################################################

SRC :=	main.c \
		builtins/cd.c \
		builtins/pwd.c \
		\
		initialize/struct_init.c \
		\
		parsing/parsing.c \
		\
		parsing/token/token.c \
		\
		parsing/token/command_assignement/command_assign_1.c \
		parsing/token/command_assignement/command_assign_utils.c \
		\
		parsing/token/line_control/line_ctrl_1.c \
		parsing/token/line_control/line_ctrl_2.c \
		parsing/token/line_control/line_ctrl_1inferior.c \
		parsing/token/line_control/line_ctrl_2inferior.c \
		parsing/token/line_control/line_ctrl_1superior.c \
		parsing/token/line_control/line_ctrl_2superior.c \
		parsing/token/line_control/line_ctrl_utils.c \
		\
		parsing/token/token_assignement/token_assign_1.c \
		parsing/token/token_assignement/token_utils_1.c \
		parsing/token/token_assignement/token_utils_2.c \
		parsing/token/token_assignement/token_utils_3.c \
		parsing/token/token_assignement/token_utils_4.c \
		\
		parsing/token/token_control/token_list_control_1.c \
		\
		parsing/token/type_assignement/type_assign_1.c \
		parsing/token/type_assignement/type_assign_2.c \
		\
		utils/free_all_1.c \
		utils/exit_error.c


SRC := $(addprefix $(SRC_DIR)/, $(SRC))

################################################################################
#                                  OBJECTS / DEP                                #
################################################################################

OBJ_DIR = obj
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

DEPS := $(OBJ:.o=.d)
DEPS += ./libft/*.d

################################################################################
#                                  ASCII ART                                   #
################################################################################

PINK = \033[1;95m
RED = \033[0;91m
CYAN = \033[0;96m
MAGENTA = \033[1;35m
RESET = \033[0m

################################################################################
#                                  MAKEFILE                                    #
################################################################################

all: $(NAME) 
		
$(NAME): $(OBJ)
	@$(MAKE) -C ./libft 
	@$(CC) $(CFLAGS) $(CIFLAGS) $(OBJ) $(LIBFT) $(CCLIED) -o $(NAME)
	@echo "\n$(CYAN)$(NAME) compiled!$(RESET)"
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ 
	@echo "$(MAGENTA)Compiling: $< $(DEF_COLOR)$(RESET)"

################################################################################
#                                  CLEAN / FCLEAN                              #
################################################################################

clean:
	@echo "\n$(RED)Removing: $(OBJ) $(OBJ_DIR) $(DEF_COLOR)$(RESET)\n"
	@$(MAKE) -C ./libft clean
	@rm -rf $(OBJ_DIR)
	@rm -f ./libft/*.d
	@rm -f libft/GNL/*.d	
	@rm -f libft/ft_printf/*.d
	@echo "$(RED)Dependencies have been removed.$(RESET)"
	@echo "$(RED)Obj directory has been removed.$(RESET)\n"

fclean: clean
	@$(MAKE) -C ./libft fclean
	@rm -f $(NAME)

valgrind : all
	valgrind --suppressions=readline_leak.txt --leak-check=full --show-leak-kinds=all --track-fds=yes ./${NAME}

re: fclean all

.EXTRA_PREREQS:= $(abspath $(lastword $(MAKEFILE_LIST)))
-include $(DEPS)