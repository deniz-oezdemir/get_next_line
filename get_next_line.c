/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:27:50 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/30 21:53:02 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_excess(char *line)
{
	char	*eol;
	char	*excess;

	eol = ft_strchr(line, '\n');
	if (!eol++)
		return (NULL);
	else
	{
		excess = ft_strdup(eol);
		*eol = '\0';
		return (excess);
	}
}

/* if buf not static, stackoverflow for high BUFFER_SIZE */
char	*read_buffer(char *line, int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		nb;

	while (!ft_strchr(line, '\n'))
	{
		nb = read(fd, buf, BUFFER_SIZE);
		if (nb == 0)
			break ;
		if (nb == -1)
		{
			free(line);
			return (NULL);
		}
		buf[nb] = '\0';
		line = ft_strjoin(line, buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*excess;
	char		*line;

	line = read_buffer(excess, fd);
	excess = extract_excess(line);
	return (line);
}
