/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:40:02 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/13 12:43:39 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *str)
{
	char	*buff;
	int		read_line;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_line = 1;
	while (!ft_strchr(str, '\n') && read_line != 0)
	{
		read_line = read(fd, buff, BUFFER_SIZE);
		if (read_line == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_line] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_read_line(fd, str[fd]);
	if (!str[fd])   
		return (NULL);
	line = ft_get_line(str[fd]);
	str[fd] = ft_switch_line(str[fd]);
	return (line);
}