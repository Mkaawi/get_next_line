/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:12:51 by abdennac          #+#    #+#             */
/*   Updated: 2024/01/13 12:08:28 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_append(char	*line, char *buffer)
{
	char	*tmp;
	
	tmp = ft_strjoin(line, buffer);
	free(line);
	return (tmp);
}

char	*rest_of_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if(!buffer[i])
		return(NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *line)
{
	char	*buffer;
	int		bytes_read;
	
	if (!line)
		line = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			printf ("1\n");
			free (line);
			free (buffer);
			buffer = NULL;
			
			return (NULL);
		}
		buffer[bytes_read] = 0;
		line = ft_append(line, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		{
			printf ("2\n");
			free (buffer);
			buffer = NULL;
			return (NULL);
		}
	line = extract_line(buffer);
	buffer = rest_of_line(buffer);
	return (line);
}