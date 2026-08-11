/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:11:12 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/18 15:37:19 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point		c_add(t_point a, t_point b)
{
	t_point	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}

t_point		c_mult(t_point a, t_point b)
{
	t_point	res;

	res.x = a.x * b.x - a.y * b.y;
	res.y = a.x * b.y + a.y * b.x;
	return (res);
}

t_point		c_sq(t_point a)
{
	return (c_mult(a, a));
}

double		c_sqmod(t_point a)
{
	return (a.x * a.x + a.y * a.y);
}
