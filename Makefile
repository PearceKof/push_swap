# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 17:12:23 by blaurent          #+#    #+#              #
#    Updated: 2022/08/24 18:16:11 by blaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

BNAME		= checker

FLAGS		= -Wall -Wextra -Werror

SRC		=	mandatory/main.c \
				mandatory/fill_stack.c \
				mandatory/position.c \
				mandatory/stack_utils.c \
				mandatory/utils.c \
				mandatory/sort.c \
				mandatory/move.c \
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

BONUS		=	bonus/checker.c \
					mandatory/fill_stack.c \
					mandatory/position.c \
					mandatory/stack_utils.c \
					mandatory/utils.c \
					mandatory/sort.c \
					mandatory/move.c \
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
					mylib/libft/ft_strncmp.c \
					mylib/libft/gnl.c \
					mylib/libft/ft_calloc.c \
					mylib/libft/ft_bzero.c \

BOBJ		= $(BONUS:%.c=%.o)

all: $(OBJ) $(NAME)

bonus: all $(BNAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

$(BNAME): $(BOBJ)
	gcc $(FLAGS) -o $(BNAME) $(BOBJ)

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