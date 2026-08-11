/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:41:33 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/24 15:47:57 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_name	which_fractal(char *str)
{
	if (ft_strequ(str, "mandelbrot") || ft_strequ(str, "man"))
		return (MANDELBROT);
	if (ft_strequ(str, "julia") || ft_strequ(str, "jul"))
		return (JULIA);
	if (ft_strequ(str, "burning ship") || ft_strequ(str, "burn"))
		return (BURNING_SHIP);
	return (NONE);
}
