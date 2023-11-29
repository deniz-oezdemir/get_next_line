/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:20:57 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/29 17:21:59 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
static void	del_line(char **storage);
static void	get_line(char **storage, char **line);
static int	read_buffer(int fd, char **storage, char *buffer);
char	*get_next_line(int fd);

#endif


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif
