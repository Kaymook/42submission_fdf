/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   izometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:03:52 by kmoshker          #+#    #+#             */
/*   Updated: 2024/06/01 19:03:54 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	default angle: 0.523599
**	make the figure 3d (isometric stile)
*/

#include "fdf.h"

void	isometric(t_dot *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}
