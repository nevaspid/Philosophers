# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 13:47:52 by gloms             #+#    #+#              #
#    Updated: 2023/11/01 21:53:41 by gloms            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	philo

# ------------------------------ Sources -----------------------------

INCLUDE := -I srcs/

SRCS		:=	srcs/main.c \
				srcs/parsing/error_handler.c \
				srcs/utils/ft_atoi.c \
				srcs/utils/ft_strlen.c \
				srcs/utils/ft_lstadd_back.c \
				srcs/utils/ft_lstnew.c \
				srcs/utils/do_circular_list.c \
				srcs/time/time_handler.c \
				srcs/time/health_handler.c \
				srcs/routine/routine.c \
				srcs/temp/randomize.c \

OBJ_DIR		:=	srcs/.objs
OBJS		:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ------------------------------ Flags -------------------------------

CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror -g3 #-fsanitize=address

$(OBJ_DIR)/%.o :%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(FLAGS) $(INC_RL) -c $< -o $@

# ------------------------------ Colors ------------------------------

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN 		:=	\033[1;36m

# ------------------------------ Compilation -------------------------

all:			$(NAME)

$(NAME):		$(OBJS)
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) $(INC_RL) $(LINK_RL) -o $(NAME) $(OBJS)
				@ echo "$(YELLOW)$(NAME) $(GREEN)created $(CLR_RMV)✔️"

# -------------------------------- Rules -----------------------------

clean:
				@ $(RM) $(OBJS)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:			clean
				@ $(RM) $(NAME) $(RM)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:				fclean all

.PHONY:			all bonus clean fclean re
