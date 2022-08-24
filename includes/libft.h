/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:48:46 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/10 15:48:46 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_freetab(char **tab);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
int		ft_putaddr_fd(unsigned long long nbr, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
int		ft_putnbr_base(long long nb, unsigned int base, char *printnb, int std);
int		ft_putstr_fd(char *s, int fd);
int		ft_putstr(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*gnl(int fd);

#endif