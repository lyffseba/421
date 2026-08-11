/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:43:08 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/22 12:19:45 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_point	julia(t_fract *fract, t_point c)
{
	return (c_add(c_sq(c), fract->julia));
}

t_felem			iter_julia(t_fract *fract, t_point c)
{
	t_felem	elem;

	elem.val.x = c.x;
	elem.val.y = c.y;
	elem.exit = -1;
	while (++(elem.exit) < ITERATIONS)
	{
		elem.val = julia(fract, elem.val);
		if (c_sqmod(elem.val) > 4)
			return (elem);
	}
	return (elem);
}
