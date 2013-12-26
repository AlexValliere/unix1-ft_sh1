# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/30 14:01:21 by apetit            #+#    #+#              #
#    Updated: 2013/12/26 16:21:12 by alexandre        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
NAME		= libft.a

SRC			=	src/ft_abs.c \
				src/ft_atoi.c \
				src/ft_bzero.c \
				src/ft_is_int.c \
				src/ft_isalnum.c \
				src/ft_isalpha.c \
				src/ft_isascii.c \
				src/ft_isdigit.c \
				src/ft_isprint.c \
				src/ft_itoa.c \
				src/ft_lstnew.c \
				src/ft_lstdelone.c \
				src/ft_lstdelfirst.c \
				src/ft_lstdel.c \
				src/ft_lstadd.c \
				src/ft_lstiter.c \
				src/ft_lstswap.c \
				src/ft_lstsize.c \
				src/ft_memalloc.c \
				src/ft_memccpy.c \
				src/ft_memchr.c \
				src/ft_memcmp.c \
				src/ft_memcpy.c \
				src/ft_memdel.c \
				src/ft_memmove.c \
				src/ft_memset.c \
				src/ft_printf.c \
				src/ft_putchar.c \
				src/ft_putstr.c \
				src/ft_putendl.c \
				src/ft_putnbr.c \
				src/ft_putchar_fd.c \
				src/ft_putstr_fd.c \
				src/ft_putendl_fd.c \
				src/ft_putnbr_fd.c \
				src/ft_putnbr_hexa.c \
				src/ft_putnbr_uint.c \
				src/ft_realloc.c \
				src/ft_strcat.c \
				src/ft_strchr.c \
				src/ft_strcmp.c \
				src/ft_strcpy.c \
				src/ft_strdup.c \
				src/ft_strlcat.c \
				src/ft_strlen.c \
				src/ft_strncat.c \
				src/ft_strncmp.c \
				src/ft_strncpy.c \
				src/ft_strnstr.c \
				src/ft_strrchr.c \
				src/ft_strstr.c \
				src/ft_strnew.c \
				src/ft_strdel.c \
				src/ft_strclr.c \
				src/ft_striter.c \
				src/ft_striteri.c \
				src/ft_strmap.c \
				src/ft_strmapi.c \
				src/ft_strequ.c \
				src/ft_strnequ.c \
				src/ft_strrev.c \
				src/ft_strsub.c \
				src/ft_strjoin.c \
				src/ft_strtrim.c \
				src/ft_strsplit.c \
				src/ft_tolower.c \
				src/ft_toupper.c \
				src/get_next_line.c

OBJ			= $(SRC:.c=.o)

CFLAGS		= -Wall -Werror -Wclobbered -Wempty-body -Wignored-qualifiers -Wmissing-field-initializers -Wmissing-parameter-type -Wold-style-declaration -Woverride-init -Wsign-compare -Wtype-limits -Wuninitialized -Wunused-but-set-parameter

RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ) includes/libft.h
			ar -q $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@ -g

.PHONY:		all clean re fclean
