/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:28:25 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/30 18:28:40 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	l;

	if (!s || !*s)
		return (NULL);
	l = ft_strlen(s);
	dst = (char *)(malloc(sizeof(char) * (l + 1)));
	if (dst == NULL)
		return (NULL);
	dst[l] = '\0';
	while (l--)
		dst[l] = s[l];	
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dst;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!dst)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	dst[len1 + len2] = '\0';
	while (len2--)
		dst[len1 + len2] = s2[len2];
	while (len1--)
		dst[len1] = s1[len1];
	if(s1)
		free(s1);
	return (dst);
}
