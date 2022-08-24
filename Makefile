# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 17:12:23 by blaurent          #+#    #+#              #
#    Updated: 2022/08/24 17:10:28 by blaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

BNAME		= checker

FLAGS		= -Wall -Wextra -Werror

SRC		=	src/fill_stack.c \
				src/position.c \
				src/stack_utils.c \
				src/utils.c \
				src/sort.c \
				src/move.c \
				pu_ro_sw/push.c \
				pu_ro_sw/swap.c \
				pu_ro_sw/rotate.c \
				pu_ro_sw/reverse_rotate.c \
				mylib/libft/ft_atoi.c \
				mylib/libft/ft_atol.c \
				mylib/libft/ft_freetab.c \
				mylib/libft/ft_isdigit.c \
				mylib/libft/ft_putstr_fd.c \
				mylib/libft/ft_split.c \
				mylib/libft/ft_strchr.c \
				mylib/libft/ft_strdup.c \
				mylib/libft/ft_strlen.c \

OBJ			= $(SRC:%.c=%.o)

BONUS		= bonus/main.c \
				mylib/libft/gnl.c \
				mylib/libft/ft_calloc.c \
				mylib/libft/ft_bzero.c \
				mylib/libft/ft_strncmp.c

BOBJ		= $(BONUS:%.c=%.o)

all: $(OBJ) $(NAME)

bonus: all $(BNAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) src/main.c $(OBJ)

$(BNAME): $(BOBJ)
	gcc $(FLAGS) -o $(BNAME) $(BOBJ) $(OBJ)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(BOBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(BNAME)

re: fclean all

.PHONY: all bonus clean fclean re