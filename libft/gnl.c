/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:20:52 by blaurent          #+#    #+#             */
/*   Updated: 2022/06/03 17:20:52 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_joinfile(char *s1, char *s2)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	free(s1);
	return (str);
}

static char	*ft_readfile(char *file, int fd)
{
	char	*tmp;
	int		end;

	end = 1;
	tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (!ft_strchr(tmp, '\n') && end != 0)
	{
		end = read(fd, tmp, BUFFER_SIZE);
		if (end == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[end] = '\0';
		file = ft_joinfile(file, tmp);
		if (!file)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	return (file);
}

static char	*ft_cpyline(char *file)
{
	char	*line;
	size_t	i;

	if (file[0] == '\0')
		return (NULL);
	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (file[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[i] = '\0';
	i = 0;
	while (file[i] && file[i] != '\n')
	{
		line[i] = file[i];
		i++;
	}
	line[i] = file[i];
	return (line);
}

static char	*ft_nxtline(char *file)
{
	char	*nxtline;
	size_t	i;
	size_t	j;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	i++;
	nxtline = malloc((ft_strlen(file + i) + 1) * sizeof(char));
	if (!nxtline)
		return (NULL);
	j = 0;
	while (file[i])
		nxtline[j++] = file[i++];
	nxtline[j] = '\0';
	free(file);
	return (nxtline);
}

char	*gnl(char **file, int fd)
{
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	*file = ft_readfile(*file, fd);
	if (!(*file))
		return (NULL);
	line = ft_cpyline(*file);
	*file = ft_nxtline(*file);
	return (line);
}
