/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:07:38 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/04 13:15:35 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

char	*create_line(char const *storage)
{
	int		i;
	char	*line;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] && storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*free_line_from_storage(char *storage)
{
	int		i;
	int		j;
	char	*newstorage;

	i = 0;
	j = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	newstorage = malloc((size_t)ft_strlen(storage) - i);
	if (!newstorage)
		return (NULL);
	while (storage[++i])
	{
		newstorage[j] = storage[i];
		j++;
	}
	newstorage[j] = '\0';
	free (storage);
	return (newstorage);
}

char	*join_and_free(char *storage, char *buffer)
{
	size_t	storage_len;
	size_t	buffer_len;
	char	*aux;

	storage_len = (size_t)ft_strlen(storage);
	buffer_len = (size_t)ft_strlen(buffer);
	aux = (char *)malloc(storage_len + buffer_len + 1);
	if (aux)
	{
		if (storage)
			ft_memcpy(aux, storage, storage_len);
		ft_memcpy(aux + storage_len, buffer, buffer_len);
		aux[storage_len + buffer_len] = '\0';
		free(storage);
	}
	return (aux);
}

char	*read_buffer(char *storage, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	bytes_read;

	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	if (!storage)
		storage = ft_calloc(1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((int)bytes_read < 0)
		{
			ft_memset(storage, 0, (size_t)ft_strlen(storage));
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = join_and_free(storage, buffer);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd < 0)
	{
		ft_memset(storage, 0, (size_t)ft_strlen(storage));
		return (NULL);
	}
	storage = read_buffer(storage, fd);
	if (!storage)
		return (NULL);
	line = create_line(storage);
	storage = free_line_from_storage(storage);
	return (line);
}
