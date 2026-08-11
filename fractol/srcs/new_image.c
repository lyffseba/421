/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:10:25 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/25 16:18:41 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int		new_image(t_fract *fract)
{
	if (!(fract->img_ptr = mlx_new_image(fract->mlx_ptr, fract->width,
					fract->height)))
		return (0);
	if (!(fract->addr = (unsigned int *)mlx_get_data_addr(fract->img_ptr,
			&(fract->image.bpp), &(fract->image.size_line),
			&(fract->image.endian))))
		return (0);
	return (1);
}
