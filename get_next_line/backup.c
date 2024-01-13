#include "get_next_line.h"

char	*join(char *static_buffer, char *buffer)
{
	char	*tmp;
	int		len1;
	int		len2;
	int		i;

	if (static_buffer && buffer)
	{
		len1 = ft_strlen(static_buffer);
		len2 = ft_strlen(buffer);
		tmp = ft_calloc(len1 + len2 + 1, sizeof(char));
		if (tmp == NULL)
			return (NULL);
		i = -1;
		while (static_buffer[++i])
			tmp[i] = static_buffer[i];
		i = -1;
		while (buffer[++i])
		{
			tmp[len1] = buffer[i];
			len1++;
		}
		free(static_buffer);
		return (tmp);
	}
	return (NULL);
}

char	*rest_of_line(char *buffer)
{
	int		rest_len;
	char	*newline_pos;
	char	*rest;

	rest_len = 0;
	newline_pos = ft_strchr(buffer, '\n');
	if (!newline_pos)
	{
		free(buffer);
		return (NULL);
	}
	rest_len = ft_strlen(newline_pos + 1);
	rest = ft_substr(buffer, newline_pos - buffer, rest_len);
	free(buffer);
	return (rest);
}

char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!i)
		return (NULL);
	line = ft_substr(buffer, 0, i);
	return (line);
}

static char	*read_file(char *final_buffer, int fd)
{
	int		byte_reader;
	char	*buffer;

	buffer = NULL;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(final_buffer, '\n'))
	{
		byte_reader = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_reader] = '\0';
		if (byte_reader < 0)
			return (free(buffer), NULL);
		if (byte_reader == 0)
			break ;
		buffer[byte_reader] = '\0';
		final_buffer = join(final_buffer, buffer);
	}
	free(buffer);
	return (final_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;
	char		*readline;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!static_buffer)
	{
		static_buffer = ft_calloc(1, sizeof(char));
		if (!static_buffer)
			return (NULL);
	}
	if (!ft_strchr(static_buffer, '\n'))
	{
		readline = read_file(static_buffer, fd);
		line = extract_line(readline);
		static_buffer = rest_of_line(readline);
		if (!readline)
			return (NULL);
		return (line);
		free(readline);
		readline = NULL;
	}
	return (NULL);
	line = extract_line(static_buffer);
	static_buffer = rest_of_line(static_buffer);
	return (line);
}