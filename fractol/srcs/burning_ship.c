/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:36:03 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/24 15:39:06 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_point	burning_ship(t_point mand, t_point c)
{
	mand.x = (mand.x < 0) ? -mand.x : mand.x;
	mand.y = (mand.y > 0) ? -mand.y : mand.y;
	return (c_add(c_sq(mand), c));
}

t_felem			iter_burning_ship(t_point c)
{
	t_felem	elem;

	elem.val.x = 0;
	elem.val.y = 0;
	elem.exit = -1;
	while (++(elem.exit) < ITERATIONS)
	{
		elem.val = burning_ship(elem.val, c);
		if (c_sqmod(elem.val) > 4)
			return (elem);
	}
	return (elem);
}
