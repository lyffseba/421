/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:17:19 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/24 14:40:21 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	end(t_fract *fract, int end_status)
{
	if (fract->mlx_ptr && fract->img_ptr)
		mlx_destroy_image(fract->mlx_ptr, fract->img_ptr);
	fract->addr = NULL;
	if (fract->mlx_ptr && fract->win_ptr)
		mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	fract->win_ptr = NULL;
	exit(end_status);
}

void	error(char *str, t_fract *fract)
{
	ft_putstr_fd("error :", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	end(fract, EXIT_ERROR);
}
