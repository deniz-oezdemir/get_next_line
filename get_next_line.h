/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:20:57 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/27 16:05:16 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);

#endif


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif
