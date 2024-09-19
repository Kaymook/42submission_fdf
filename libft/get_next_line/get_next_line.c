/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 06:55:51 by mosh              #+#    #+#             */
/*   Updated: 2024/09/19 21:51:11 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "libft.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*memory[OPEN_MAX + 1];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!memory[fd])
	{
		memory[fd] = (char *)malloc(1 * sizeof(char));
		if (!memory[fd])
			return (free(memory[fd]), NULL);
		memory[fd][0] = '\0';
	}
	memory[fd] = read_line(fd, memory[fd]);
	if (!memory[fd])
		return (free(memory[fd]), NULL);
	line = trim_line(memory[fd]);
	memory[fd] = trim_over_line(memory[fd]);
	return (line);
}

char	*read_line(int fd, char *memory)
{
	char	*buf;
	int		byte;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free(memory), NULL);
	byte = 1;
	while (!ft_strchr(memory, '\n') && byte != 0)
	{
		if (!memory)
			return (free(buf), NULL);
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte < 0)
			return (free(buf), free(memory), NULL);
		buf[byte] = '\0';
		memory = ft_strjoin(memory, buf);
		if (!memory)
			return (free(buf), NULL);
	}
	free(buf);
	return (memory);
}

char	*trim_line(char *memory)
{
	char	*line;
	int		i;

	i = 0;
	if (!memory[i])
		return (NULL);
	while (memory[i] && memory[i] != '\n')
		i++;
	line = (char *)malloc((i + 1 + 1) * sizeof(char));
	if (!line)
		return (free(line), NULL);
	i = 0;
	while (memory[i] && memory[i] != '\n')
	{
		line[i] = memory[i];
		i++;
	}
	if (memory[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*trim_over_line(char *memory)
{
	ssize_t		i;
	size_t		j;
	char		*n_line;

	i = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (!memory[i])
		return (free(memory), NULL);
	n_line = (char *)malloc((ft_strlen(memory) - i + 1) * sizeof(char));
	if (!n_line)
		return (free(memory), free(n_line), NULL);
	j = 0;
	while (memory[++i])
		n_line[j++] = memory[i];
	n_line[j] = '\0';
	free(memory);
	return (n_line);
}
