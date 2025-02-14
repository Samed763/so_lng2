/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sadinc@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:22:33 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/06 02:40:54 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*ft_next_line(char *remainder)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (remainder[i] != '\0' && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\0')
		return (free(remainder), NULL);
	tmp = (char *)malloc(ft_strlen(remainder) - i + 1);
	if (!tmp)
		return (NULL);
	i++;
	while (remainder[i])
		tmp[j++] = remainder[i++];
	tmp[j] = '\0';
	free(remainder);
	return (tmp);
}

static char	*ft_get_line(char *remainder)
{
	int		i;
	char	*line;

	i = 0;
	if (remainder[i] == '\0')
		return (NULL);
	while (remainder[i] != '\n' && remainder[i] != '\0')
		i++;
	if (ft_strchr(remainder))
		line = (char *)malloc(i + 2);
	else
		line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] != '\0' && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_reader(int fd, char *remainder)
{
	char	*temp;
	int		read_len;

	read_len = 1;
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (!ft_strchr(remainder) && read_len != 0)
	{
		read_len = read(fd, temp, BUFFER_SIZE);
		if (read_len == -1)
			return (free(remainder), free(temp), NULL);
		temp[read_len] = '\0';
		remainder = ft_strjoin(remainder, temp);
	}
	free(temp);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(remainder);
		return (NULL);
	}
	remainder = ft_reader(fd, remainder);
	if (!remainder)
		return (NULL);
	line = ft_get_line(remainder);
	remainder = ft_next_line(remainder);
	return (line);
}
