/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:21:48 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/22 12:27:39 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_point	mandelbrot(t_point mand, t_point c)
{
	return (c_add(c_sq(mand), c));
}

t_felem			iter_mandelbrot(t_point c)
{
	t_felem	elem;

	elem.val.x = 0;
	elem.val.y = 0;
	elem.exit = -1;
	while (++(elem.exit) < ITERATIONS)
	{
		elem.val = mandelbrot(elem.val, c);
		if (c_sqmod(elem.val) > 4)
			return (elem);
	}
	return (elem);
}
