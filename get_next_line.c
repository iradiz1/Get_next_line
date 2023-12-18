/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:41:36 by hzibari           #+#    #+#             */
/*   Updated: 2023/12/18 14:38:21 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_line(char *storage, char *file)
{
	char	*temp;

	temp = ft_strjoin(storage, file);
	free (storage);
	return (temp);
}

char	*next_line(char *storage)
{
	int		a;
	int		c;
	char	*temp;

	a = 0;
	c = 0;
	temp = storage;
	while (storage[a] != '\0' && storage[a] != '\n')
		a++;
	if (!storage[a])
	{
		free(storage);
		return (NULL);
	}
	a++;
	while (storage[a] != '\0')
	{
		temp[c] = storage[a];
		a++;
		c++;
	}
	temp[c++] = '\0';
	return (temp);
}

char	*the_line(char *storage)
{
	char	*the_one;
	int		i;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	the_one = ft_calloc(sizeof(char), i + 1);
	if (!the_one)
		free(storage);
	if (!the_one)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		the_one[i] = storage[i];
		i++;
	}
	if (storage[i] && storage[i] == '\n')
		the_one[i++] = '\n';
	return (the_one);
}

char	*read_file(int fd, char *storage)
{
	char	file[BUFFER_SIZE + 1];
	int		bytes;

	bytes = 1;
	if (!storage)
		storage = ft_calloc(1, 1);
	if (!storage)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read(fd, file, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		file[bytes] = '\0';
		storage = join_line(storage, file);
		if (!storage || ft_strchr(file, '\n'))
			break ;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*ret;

	if (read(fd, NULL, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
	{
		free (storage);
		storage = NULL;
		return (NULL);
	}
	storage = read_file(fd, storage);
	if (!storage || !storage[0])
	{
		free (storage);
		storage = NULL;
		return (NULL);
	}
	ret = the_line(storage);
	if (!ret)
	{
		storage = NULL;
		return (NULL);
	}
	storage = next_line(storage);
	return (ret);
}
