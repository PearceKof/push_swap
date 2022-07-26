NAME		= push_swap

FLAGS		= -Wall -Wextra -Werror

FILES		= main.c \
				stack_utils.c \
				utils.c \
				mylib/libft/ft_atoi.c \
				mylib/ft_fprintf/ft_fprintf.c \
				mylib/ft_fprintf/ft_fprint_c.c \
				mylib/ft_fprintf/ft_fprint_p.c \
				mylib/ft_fprintf/ft_fprint_s.c \
				mylib/ft_fprintf/ft_fprint_u.c \
				mylib/ft_fprintf/ft_fprint_x.c \
				mylib/ft_fprintf/ft_fprint_di.c \
				mylib/libft/ft_bzero.c \
				mylib/libft/ft_calloc.c \
				mylib/libft/ft_isalnum.c \
				mylib/libft/ft_isalpha.c \
				mylib/libft/ft_isascii.c \
				mylib/libft/ft_isdigit.c \
				mylib/libft/ft_isprint.c \
				mylib/libft/ft_itoa.c \
				mylib/libft/ft_memchr.c \
				mylib/libft/ft_memcmp.c \
				mylib/libft/ft_memcpy.c \
				mylib/libft/ft_memmove.c \
				mylib/libft/ft_memset.c \
				mylib/libft/ft_putaddr_fd.c \
				mylib/libft/ft_putchar_fd.c \
				mylib/libft/ft_putendl_fd.c \
				mylib/libft/ft_putnbr_base.c \
				mylib/libft/ft_putnbr_fd.c \
				mylib/libft/ft_putstr_fd.c \
				mylib/libft/ft_putstr.c \
				mylib/libft/ft_split.c \
				mylib/libft/ft_strchr.c \
				mylib/libft/ft_strdup.c \
				mylib/libft/ft_striteri.c \
				mylib/libft/ft_strjoin.c \
				mylib/libft/ft_strlcat.c \
				mylib/libft/ft_strlcpy.c \
				mylib/libft/ft_strlen.c \
				mylib/libft/ft_strmapi.c \
				mylib/libft/ft_strncmp.c \
				mylib/libft/ft_strnstr.c \
				mylib/libft/ft_strrchr.c \
				mylib/libft/ft_strtrim.c \
				mylib/libft/ft_substr.c \
				mylib/libft/ft_tolower.c \
				mylib/libft/ft_toupper.c \
				mylib/libft/ft_lstnew.c \
				mylib/libft/ft_lstadd_front.c \
				mylib/libft/ft_lstsize.c \
				mylib/libft/ft_lstlast.c \
				mylib/libft/ft_lstadd_back.c \
				mylib/libft/ft_lstdelone.c \
				mylib/libft/ft_lstclear.c \
				mylib/libft/ft_lstiter.c \
				mylib/libft/ft_lstmap.c \


OBJ			= $(FILES:%.c=%.o)

all: $(OBJ) $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re