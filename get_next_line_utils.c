/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:28:25 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/29 17:38:09 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*string;

	i = 0;
	string = (char *)s;
	while (n > 0)
	{
		string[i] = c;
		i++;
		n--;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
*/

//replacing my functions with this did not help debugging - BUT can we use 4 or 5 functions per file?
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = '\0';
		i++;
	}
}

char	*ft_strchr(const char *s, int c) //mine is different, added NULL check and THIS FIXED MOST ERRORS! understand why!
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

/*including this instead of mine did not help while debugging
char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	if (s == NULL) //added while debugging, test removing
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1 && *s1) //why? compare with version from piscine
	{
		dst[i++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		dst[i++] = *s2;
		s2++;
	}
	dst[i] = '\0';
	return (dst);
}
