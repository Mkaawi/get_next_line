/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:41:45 by abdennac          #+#    #+#             */
/*   Updated: 2024/01/09 18:26:21 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void print_n(char *buffer)
{
	int i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\\';
			// printf("%c\n", buffer[i]);
		}
		i++;
	}
}

// static int	count = 1;
// printf("[%d]", count++);

char *join(char *final_buffer, char *buffer)
{
	char *tmp;

	tmp = ft_strjoin(final_buffer, buffer);
	
	free(final_buffer);
	return (tmp);
}

char *extract_line(char *final_buffer)
{
	int i  = 0;
	while(final_buffer[i] && final_buffer[i] != '\n')
		i++;
	char *line = ft_substr(final_buffer, 0, i);
	return (line);
}

char *restof(char *final_buffer)
{
	char	*rest;
	char	*newline_pos;
	int		rest_ln;

	newline_pos = ft_strchr(final_buffer, '\n');
	if(!newline_pos)
	{
		free(final_buffer);
		return (ft_strdup(""));
	}
	rest_ln = ft_strlen(newline_pos + 1);
	rest = ft_substr(final_buffer, newline_pos - final_buffer + 1, rest_ln);
	free (final_buffer);
	return (rest);
}

static char *read_file(char *final_buffer, int fd)
{
	int byte_reader;
	char *buffer = NULL;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	
	while (!ft_strchr(final_buffer, '\n'))
	{
		byte_reader = read(fd, buffer, BUFFER_SIZE);
		if (byte_reader <= 0)
			return (free(buffer), NULL);
		buffer[byte_reader] = '\0';
		final_buffer = join(final_buffer, buffer);
	}
	free(buffer);
	return (final_buffer);
}

char *get_next_line(int fd)
{
	static char *final_buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!final_buffer)
	{
		final_buffer = ft_calloc(1, sizeof(char));
		final_buffer[0] = '\0';
	}
	if (!ft_strchr(final_buffer, '\n'))
		final_buffer = read_file(final_buffer, fd);

	if (!final_buffer)
		return (free(final_buffer), NULL);
	line =extract_line(final_buffer);
	final_buffer = restof(final_buffer);
	return (line);
}