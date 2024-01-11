/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:33:12 by hzibari           #+#    #+#             */
/*   Updated: 2023/12/18 12:24:23 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	l;
	int		len;

	l = c;
	len = ft_strlen(s) + 1;
	while (len > 0)
	{
		if (*s == l)
			return ((char *)s);
		s++;
		len--;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	int				h;
	unsigned char	*p;

	p = s;
	h = 0;
	while (n > 0)
	{
		p[h] = '\0';
		n--;
		h++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	max;

	max = 0 - 1;
	if (count != 0 && size != 0)
		if (max / count < size)
			return (0);
	if ((count * size) > 2147483423)
		return (0);
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero (ptr, count * size);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		c;

	c = 0;
	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == 0)
		return (0);
	while (s1[c] != '\0')
	{
		dest[c] = s1[c];
		c++;
	}
	while (s2[i] != '\0')
	{
		dest[c + i] = s2[i];
		i++;
	}
	dest[c + i] = '\0';
	return (dest);
}
