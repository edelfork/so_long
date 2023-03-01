/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:31:50 by dripanuc          #+#    #+#             */
/*   Updated: 2022/02/24 18:42:03 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	check_row(char *s)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_get_buff(int i, char *buffer_line, char *buff, int fd)
{
	while (i > 0 && check_row(buffer_line) == 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == 0)
			break ;
		else if (i < 0)
			return (NULL);
		buffer_line = ft_strjoin_free(buffer_line, buff, i);
		if (ft_strlen_gnl(buffer_line) == 0)
		{
			free(buffer_line);
			free(buff);
			return (NULL);
		}
	}
	if (i < 0)
	{
		free(buffer_line);
		free(buff);
		return (NULL);
	}
	return (buffer_line);
}

char	*get_next_line(int fd)
{
	static char	*b_line = NULL;
	char		*buff;
	char		*res;
	size_t		i;
	int			c;

	if (fd > 256 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	c = 0;
	res = NULL;
	buff = malloc(BUFFER_SIZE + 1);
	buff[BUFFER_SIZE] = 0;
	i = 1;
	b_line = ft_get_buff(i, b_line, buff, fd);
	if (b_line == NULL)
	{
		free(b_line);
		free(buff);
		return (NULL);
	}
	c = ft_strchr_edit(b_line, '\n');
	res = ft_substr_edit(b_line, 0, c, 0);
	b_line = ft_substr_edit(b_line, c + 1, ft_strlen_gnl(b_line), 1);
	free(buff);
	return (res);
}
