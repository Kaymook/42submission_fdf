/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:03:18 by kmoshker          #+#    #+#             */
/*   Updated: 2024/09/09 02:08:11 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include "../minilibx_macos/mlx.h"

// # define PRM  matrix[0][0]888

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
	int			is_last;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_dot;

t_dot			**read_map(char *file_name);
void			isometric(t_dot *dot, double angle);
// void			draw(t_dot **matrix);
void			draw(t_dot **matrix, t_dot *prm);
int				deal_key(int key, t_dot **matrix, t_dot *prm);
void			set_param(t_dot *a, t_dot *b, t_dot *param);
void			print_menu(t_dot param);
void			ft_error(char *msg);
void			new_window(int key, t_dot **matrix, t_dot *prm);
int				open_file(char *file);
int				get_width(char *file);
int				get_height(char *file);
void			arg_error(int error);


#endif
