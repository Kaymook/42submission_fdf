/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:03:35 by kmoshker          #+#    #+#             */
/*   Updated: 2024/09/09 00:24:08 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		get_dots_from_line(char *line, t_dot **matrix_of_dots, int y)
{
	char	**dots;
	int		x;

	dots = ft_split(line, ' ');
	x = 0;
	while (dots[x])
	{
		matrix_of_dots[y][x].z = ft_atoi(dots[x]);
		matrix_of_dots[y][x].x = x;
		matrix_of_dots[y][x].y = y;
		matrix_of_dots[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	free(line);
	matrix_of_dots[y][--x].is_last = 1;
	return (x);
}

t_dot	**memory_allocete(char *file_name)
{
	t_dot	**new;
	int		x;
	int		y;

	x = get_width(file_name);
	y = get_height(file_name);
	new = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1));
	while (y > 0)
		new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
	return (new);
}

t_dot	**read_map(char *file_name)
{
	t_dot	**matrix_of_dots;
	int		i;
	int		fd;
	char	*line;

	fd = open_file(file_name);
	matrix_of_dots = memory_allocete(file_name);
	i = 0;
	while (get_height(file_name) > i)
	{
		line = get_next_line(fd);
		get_dots_from_line(line, matrix_of_dots, i++);
	}
	// free(line);
	matrix_of_dots[i] = NULL;
	close(fd);
	return (matrix_of_dots);
}


int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (0 >= fd)
		ft_error("could not open the file, retry");
	return (fd);
}

int	get_width(char *file)
{
	int		width;
	int		fd;
	char	*line;

	fd = open_file(file);
	line = get_next_line(fd);
	if (!line)
		ft_error("gnl");
	while (get_next_line(fd))
		;
	width = count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int	get_height(char *file)
{
	int		height;
	int		fd;
	char	*gnl;

	fd = open_file(file);
	height = 0;
	gnl = get_next_line(fd);
	while (gnl)
	{
		height++;
		free(gnl);
		gnl = get_next_line(fd);
	}
	free (gnl);
	close(fd);
	return (height);
}
