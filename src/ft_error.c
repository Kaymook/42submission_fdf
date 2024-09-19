/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:03:57 by kmoshker          #+#    #+#             */
/*   Updated: 2024/06/01 19:03:58 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	arg_error(int error)
{
	if (error == 2)
	{
		return ;
	}
	else if (error != 2)
		ft_error("usage: ./fdf map.fdf");
}
