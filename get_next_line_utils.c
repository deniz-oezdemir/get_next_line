/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:28:25 by denizozd          #+#    #+#             */
/*   Updated: 2023/12/01 12:40:44 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*The ft_strchr function searches for the first occurrence of a specified
	character in a string
	and returns a pointer to that character,
	or NULL if the character is not found;
	it includes a check for a NULL string input.*/
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

/*The ft_strdup function duplicates a given string,
	allocating memory for the duplicate,
	and returns a pointer to the duplicated string
	or NULL if the input string is NULL or empty.*/
char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	l;
	size_t	i;

	if (!s || !*s)
		return (NULL);
	l = ft_strlen(s);
	dst = (char *)(malloc((l + 1) * sizeof(char)));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		dst[i] = s[i];
		i++;
	}
	dst[l] = '\0';
	return (dst);
}

/*The ft_strjoin function concatenates two strings, s1 and s2,
	by allocating memory for a new string containing their combined content,
	freeing the memory allocated for s1,
	and returns a pointer to the new concatenated string
	or NULL in case of memory allocation failure.*/
char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dst;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)malloc((len1 + len2 + 1) * sizeof(char));
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
	if (s1)
		free(s1);
	return (dst);
}
