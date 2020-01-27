/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 01:34:56 by ztaouil           #+#    #+#             */
/*   Updated: 2019/11/05 01:35:02 by ztaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t          ft_strlen(const char *str)
{
	size_t  c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char            *ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
	char            *dest;
	size_t          i;
	size_t          j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		dest[i] = ((char *)s1)[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		dest[i + j] = ((char *)s2)[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char            *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t          index;
	char            *substr;

	if (!s)
		return (NULL);
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	index = 0;
	if (!(start > ft_strlen(s)))
	{
		while (index < len && s[start + index])
		{
			substr[index] = s[start + index];
			index++;
		}
	}
	substr[index] = '\0';
	return (substr);
}

char    *ft_strdup(const char *s1)
{
	size_t  s1_len;
	char    *ptr;
	size_t  index;
	char    *str;

	str = (char *)s1;
	index = 0;
	s1_len = ft_strlen((char *)s1);
	if (!(ptr = (char *)malloc(sizeof(char) * s1_len + 1)))
		return (0);
	while (index < s1_len)
	{
		ptr[index] = str[index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
