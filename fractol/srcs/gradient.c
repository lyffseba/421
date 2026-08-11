/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:09:23 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/25 17:55:52 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ratio(int start, int end, int current)
{
	return ((double)(current - start) / (double)(end - start));
}

int		color_lvl(int start, int end, double ratio)
{
	return ((int)((1 - ratio) * start + ratio * end));
}

int		gradient(double ratio, int start, int end)
{
	int		red;
	int		green;
	int		blue;

	red = color_lvl((start >> 16) & 0xFF, (end >> 16) & 0xFF, ratio);
	green = color_lvl((start >> 8) & 0xFF, (end >> 8) & 0xFF, ratio);
	blue = color_lvl(start & 0xFF, end & 0xFF, ratio);
	return ((red << 16) | (green << 8) | blue);
}
