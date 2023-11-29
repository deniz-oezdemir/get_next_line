/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:27:50 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/29 12:52:52 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	get_line(char **storage, char **line)
{
	char	*new_line_char;
	size_t	len_line;
	size_t	i;

	new_line_char = ft_strchr(*storage, '\n');
	len_line = ft_strlen(*storage) - ft_strlen(new_line_char) + 2;
	*line = (char *)malloc(len_line *sizeof(char));
	if (!line)
		return (0);
	i = -1; //changed indexing to be more concise
	while (i++ < len_line - 1)
		(*line)[i] = (*storage)[i];
	(*line)[i] = '\0';
}	


static int	read_buffer(int fd, char **storage, char *buffer)
{
	char	*tmp; //evtl. ohne tmp moeglich? Nutzung der variables auf schema bringen und ggf. optimizen
	int	bytes; //nbyte nennen

	bytes = read(fd, buffer, BUFFER_SIZE); //rename bytes better
	if (bytes < 0 || buffer == NULL) //test whether chage to bytes == -1 worls as read returns -1 in case of error
	{
		free(*storage);
		*storage = NULL; 
		return (-1);
	}
	if (bytes == 0) //read returns 0 when end of file
		return (0);
	tmp = ft_strjoin(*storage, buffer);
	free(*storage);	
	*storage = tmp;
	return (bytes);
}
	

char	*get_next_line(int fd)
{
	static char	*storage;
	char	*line;
	char	*buffer; //buf abkuerzen
	int	bytes; //nbyte nennen, size_t nutzen	

	storage = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer) //added
		return (0);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes = 1;
	while (strchr(storage, '\n') == NULL && bytes > 0) //testen ob bytes != 0 auch funktioniert
		bytes = read_buffer(fd, &storage, buffer);
	free(buffer);
	if (bytes == -1)
		return (0);	
	if (ft_strlen(storage) = 0) //warum notwendig?
		return (0);
	get_line(&storage, &line);
	del_line(&storage);
	return(line);
	
}
