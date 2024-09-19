/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:04:04 by kmoshker          #+#    #+#             */
/*   Updated: 2024/09/09 02:09:42 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"


float	fmodule(float i)
{
	if (i < 0)
	{
		return (-i);
	}
	else
	{
		return (i);
	}
}

float	ft_max(float a, float b)
{
	if (a > b)
	{
		return (a);
	}
	else if (a < b)
		return (b);
	return (a);
}

void	line(t_dot a, t_dot b, t_dot *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = ft_max(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	color = (b.z || a.z) ? 0xfc0345 : 0xBBFAFF;
	color = (b.z != a.z) ? 0xfc031c : color;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw(t_dot **matrix, t_dot *prm)
{
	int		y;
	int		x;

	print_menu(*prm);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], prm);
			if (!matrix[y][x].is_last)
				line(matrix[y][x], matrix[y][x + 1], prm);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
