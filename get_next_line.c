/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:27:50 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/27 17:26:58 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> //to be deleted

void	print_newline_helper(char *buffer)
{
	while (*buffer && *buffer != '\0')
	{
		if (*buffer == '\n')
		{
			*buffer = '\\';
		}
		printf("%c", *buffer);
		buffer++;
	}
}

static char *read_from_file(int fd)
{
	int	bytes_read;
	char	*cup_buffer;
	static int	count = 1;

	printf("ft_calloc#[%d]---", count++);
	cup_buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	print_newline_helper(cup_buffer);

	if (bytes_read <= 0)
		return (free (cup_buffer), NULL);
	return (cup_buffer);
}

char	*get_next_line(int fd)
{
	char *basin_buffer;

	basin_buffer = read_from_file(fd);
	return (basin_buffer);
}
