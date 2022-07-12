/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoin-sh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:39:31 by smoin-sh          #+#    #+#             */
/*   Updated: 2022/06/25 13:21:36 by smoin-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *buff)
{
	size_t	fd_len;
	char	*str;

	str = (char *) malloc ((sizeof(char) * BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	fd_len = 1;
	while (fd_len != 0 && ft_strchr(buff, '\n') == 0)
	{
		fd_len = read(fd, str, BUFFER_SIZE);
		if ((int) fd_len == -1)
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

char	*ft_define_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	line = (char *) malloc (sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*nline;
	static char	*buff[4096];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff[fd] = ft_read_line(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	nline = ft_define_line(buff[fd]);
	buff[fd] = ft_new_buff(buff[fd]);
	return (nline);
}
