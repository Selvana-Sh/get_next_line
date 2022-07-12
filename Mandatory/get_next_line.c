/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoin-sh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:12:34 by smoin-sh          #+#    #+#             */
/*   Updated: 2022/06/25 13:21:16 by smoin-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *buff)
{
	int		fd_len;
	char	*str;

	str = (char *) malloc ((sizeof(char) * BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	fd_len = 1;
	while (fd_len != 0 && ft_strchr(buff, '\n') == 0)
	{
		fd_len = read(fd, str, BUFFER_SIZE);
		if (fd_len == -1)
		{
			free (str);
			return (NULL);
		}
		str[fd_len] = '\0';
		buff = ft_strjoin(buff, str);
	}
	free (str);
	return (buff);
}

char	*ft_define_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = (char *) malloc (sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*nline;
	static char	*buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = ft_read_line(fd, buff);
	if (!buff)
		return (NULL);
	nline = ft_define_line(buff);
	buff = ft_new_buff(buff);
	return (nline);
}
