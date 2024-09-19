/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_window_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:04:20 by kmoshker          #+#    #+#             */
/*   Updated: 2024/09/09 02:13:36 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_win_size(int key, t_dot *prm)
{
	if ((key == 0 && prm->win_y <= 500) || (key == 6 && prm->win_x <= 500))
		return (1);
	if ((key == 1 && prm->win_y > 1000) || (key == 7 && prm->win_x > 2000))
		return (1);
	return (0);
}

// void	full_screen(t_dot **matrix)
// {
// 	static int old_x;
// 	static int old_y;

// 	if (PRM.win_x != 2560)
// 	{
// 		old_x = PRM.win_x;
// 		old_y = PRM.win_y;
// 	}
// 	PRM.win_x = (PRM.win_x == 2560) ? old_x : 2560;
// 	PRM.win_y = (PRM.win_y == 1400) ? old_y : 1400;
// }

void	change_window_size(int key, t_dot *prm)
{
	if (check_win_size(key, prm))
		return ;
	if (key == 6)
		prm->win_x -= 100;
	if (key == 7)
		prm->win_x += 100;
	if (key == 0)
		prm->win_y -= 100;
	if (key == 1)
		prm->win_y += 100;
}

void	new_window(int key, t_dot **matrix, t_dot *prm)
{
	change_window_size(key, prm);
	if (prm->win_ptr)
	{
		mlx_destroy_window(prm->mlx_ptr, prm->win_ptr);
		prm->win_ptr = NULL;
	}
	prm->mlx_ptr = mlx_init();
	prm->win_ptr = mlx_new_window(prm->mlx_ptr, prm->win_x, prm->win_y, "FDF");
	prm->shift_x = prm->win_x / 3;
	prm->shift_y = prm->win_y / 3;
	draw(matrix, prm);
	mlx_key_hook(prm->win_ptr, deal_key, matrix);
	mlx_loop(prm->mlx_ptr);
}
