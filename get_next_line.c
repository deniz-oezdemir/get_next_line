/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:27:50 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/29 18:29:18 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	del_line(char **storage)
{
	char	*new_line_char;
	char	*tmp;
	size_t	i;
	size_t	j;

	new_line_char = ft_strchr(*storage, '\n');
	if (!new_line_char)
	{
		free(*storage);
		*storage = NULL;
		return ;
	}
	tmp = malloc((ft_strlen(new_line_char)) * sizeof(char));
/*
	if (!tmp)
		return ;
*/
	i = 0;
	j = ft_strlen(*storage) - ft_strlen(new_line_char) + 1;
	while (j < ft_strlen(*storage))
		tmp[i++] = (*storage)[j++]; //bis hierer scheint es unnoetig komplex und vereinfachbar
	tmp[i] = '\0';
	free(*storage);
	*storage = tmp;
	if (**storage == 0) //was wird hier gecheckt?
	{
		free(*storage);
		*storage = NULL;
	}
}	
	
static void	get_line(char **storage, char **line)
{
	char	*new_line_char;
	size_t	len_line;
	size_t	i;

	new_line_char = ft_strchr(*storage, '\n');
	len_line = ft_strlen(*storage) - ft_strlen(new_line_char) + 2;
	*line = (char *)malloc(len_line *sizeof(char));
	if (!line)
		return ;
	i = 0;
	while (i < len_line - 1) //index more concise
	{
		(*line)[i] = (*storage)[i];
		i++;
	}
	(*line)[i] = '\0';
}	


static int	read_buffer(int fd, char **storage, char *buffer)
{
	char	*tmp; //evtl. ohne tmp moeglich? Nutzung der variables auf schema bringen und ggf. optimizen
	int	bytes; //nbyte nennen

	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE); //rename bytes better
	if (bytes < 0 || buffer == NULL) //test whether chage to bytes == -1 worls as read returns -1 in case of error
	{
		free(*storage);
		*storage = NULL; 
		return (-1);
	}
	if (bytes == 0) //read returns 0 when end of file
		return (bytes); //test changing to 0 instead of bytes
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
		return (NULL); //always return NULL not 0 if funtion return parameter is string
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
/*	if (!buffer) //added, did not change anything
		return (NULL); */
	bytes = 1;
	while (ft_strchr(storage, '\n') == NULL	&& bytes > 0) //testen ob bytes != 0 auch funktioniert
		bytes = read_buffer(fd, &storage, buffer);
	free(buffer);
	if (bytes == -1)
		return (NULL);	
	if (ft_strlen(storage) == 0) //warum notwendig?
		return (NULL);
	get_line(&storage, &line);
	del_line(&storage);
	return(line);
}
