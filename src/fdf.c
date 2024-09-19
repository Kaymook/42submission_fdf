/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:03:07 by kmoshker          #+#    #+#             */
/*   Updated: 2024/09/19 21:45:22 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 50;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr = \
	mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
	if (!param->win_ptr)
		ft_error("mlx_new_window");
}


static int	destroy(t_dot *data, t_dot **matrix)
{
	(void)matrix;
	(void)data;
	exit(0);
}
// __attribute__((destructor))static void destructor()
// {
// 	system("leaks -q fdf");
// }
int	main(int argc, char **argv)
{
	t_dot	**matrix;
	t_dot	prm;

	arg_error(argc);
	matrix = read_map(*++argv);
	set_default(&prm);
	draw(matrix, &prm);
	mlx_hook(prm.win_ptr, 17, 0, destroy,  matrix);
	mlx_key_hook(prm.win_ptr, deal_key, matrix);	
	mlx_loop(prm.mlx_ptr);
}
