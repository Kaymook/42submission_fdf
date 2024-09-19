/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:04:13 by kmoshker          #+#    #+#             */
/*   Updated: 2024/09/15 01:27:04 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 ||\
	key == 91 || key == 28 || key == 84 || key == 19 ||\
	key == '~' || key == '}' || key == '{' || key == '|' ||\
	key == 87 || key == 23 || key == 86 || key == 21 ||\
	key == 49 || key == 88 || key == 22);
}

void	do_key(int key, t_dot *prm)
{
	if (key == 24 || key == 69)
		prm->scale += 3;
	if (key == 27 || key == 78)
		prm->scale -= 3;
	if (key == 91 || key == 28)
		prm->z_scale += 1;
	if (key == 84 || key == 19)
		prm->z_scale -= 1;
	if (key == '~')
		prm->shift_y -= 10;
	if (key == '}')
		prm->shift_y += 10;
	if (key == '{')
		prm->shift_x -= 10;
	if (key == '|')
		prm->shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
		prm->is_isometric = (prm->is_isometric) ? 0 : 1;
	if (key == 86 || key == 21)
		prm->angle += 0.05;
	if (key == 88 || key == 22)
		prm->angle -= 0.05;
}

int		deal_key(int key, t_dot **matrix, t_dot *prm)
{
	if (is_key(key))
   	{
        if (prm->mlx_ptr && prm->win_ptr)
        {
            mlx_clear_window(prm->mlx_ptr, prm->win_ptr);
            do_key(key, prm);
            print_menu(*prm);
            draw(matrix, prm);
        }
    }
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, matrix, prm);
	if (key == 53)
    {
        // if (prm->mlx_ptr && prm->win_ptr)
        // {
        //     mlx_destroy_window(prm->mlx_ptr, prm->win_ptr);
        //     free(matrix);
        // }
        exit(0);
    }
	return (0);
}

