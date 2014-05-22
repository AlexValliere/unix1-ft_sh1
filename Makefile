# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apetit <apetit@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/24 21:56:51 by apetit            #+#    #+#              #
#    Updated: 2014/05/18 16:07:50 by apetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
NAME		= ft_minishell1
SRC			=	srcs/main.c \
				srcs/ft_cd.c \
				srcs/ft_count_arg.c \
				srcs/ft_display_prompt.c \
				srcs/ft_dup_environ.c \
				srcs/ft_exec_bin.c \
				srcs/ft_exit.c \
				srcs/ft_get_envhome.c \
				srcs/ft_get_envoldpwd.c \
				srcs/ft_get_envpath.c \
				srcs/ft_get_envpwd.c \
				srcs/ft_get_pwd.c \
				srcs/ft_print_environ.c \
				srcs/ft_parse_input.c \
				srcs/ft_setenv.c \
				srcs/ft_unsetenv.c \
				srcs/ft_fork.c
OBJ			= $(SRC:.c=.o)
CFLAGS		= -Wall -Werror -Wextra
LIBFT_DIR	= ./libft
RM			= rm -rf

all:		make_lib $(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -L $(LIBFT_DIR)/ -lft

make_lib:
			cd $(LIBFT_DIR) && $(MAKE)

clean:
			cd $(LIBFT_DIR) && $(MAKE) $@
			$(RM) $(OBJ)

fclean:		clean
			cd $(LIBFT_DIR) && $(MAKE) $@
			$(RM) $(NAME)

re:			fclean all

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -I $(LIBFT_DIR)/includes/ -o $@ -g

.PHONY:		all clean re fclean
