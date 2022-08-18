# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 17:12:23 by blaurent          #+#    #+#              #
#    Updated: 2022/08/18 16:56:45 by blaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

FLAGS		= -Wall -Wextra -Werror

FILES		= main.c \
				fill_stack.c \
				position.c \
				stack_utils.c \
				utils.c \
				sort.c \
				move.c \
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

OBJ			= $(FILES:%.c=%.o)

all: $(OBJ) $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re