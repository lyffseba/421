/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:31:46 by anleclab          #+#    #+#             */
/*   Updated: 2019/03/04 15:44:55 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_event(int button, int x, int y, t_fract *fract)
{
	if (button != MOUSE_SCROLL_UP && button != MOUSE_SCROLL_DOWN)
		return (0);
	if (fract->mode == COLOR)
	{
		if (button == MOUSE_SCROLL_UP)
			fract->color = (fract->color + 1) % (NB_COLOR_SCHEMES);
		else
			fract->color = (fract->color == 0) ? NB_COLOR_SCHEMES - 1
				: fract->color - 1;
	}
	else
		zoom(fract, button, coord(fract, x, y));
	if (!draw_fractal(fract))
		error("failed to draw fractal", fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0,
			0);
	return (0);
}

int		close_win(t_fract *fract)
{
	end(fract, EXIT_OK);
	return (0);
}

int		key_release(int key, t_fract *fract)
{
	if (key == ESC)
		end(fract, EXIT_OK);
	else if (key == C)
		fract->mode = (fract->mode + 1) % 2;
	else if (key == M)
		fract->is_active_mouse = (fract->is_active_mouse) ? 0 : 1;
	else if (key == SPACE || (fract->name == JULIA && is_letter_direction(key)))
	{
		if (key == SPACE)
			fract->color = (fract->color + 1) % NB_COLOR_SCHEMES;
		else if (is_letter_direction(key))
			change_julia_param(fract, key);
		if (!draw_fractal(fract))
			error("failed to draw fractal", fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr,
				0, 0);
	}
	return (0);
}

int		mouse_move(int x, int y, t_fract *fract)
{
	if (fract->is_active_mouse)
		if (fract->name == JULIA)
		{
			fract->mouse.prev_x = (!fract->mouse.x) ? x : fract->mouse.x;
			fract->mouse.prev_y = (!fract->mouse.y) ? y : fract->mouse.y;
			fract->mouse.x = x;
			fract->mouse.y = y;
			fract->julia.x += (double)(fract->mouse.x - fract->mouse.prev_x)
					/ 10000;
			fract->julia.y += (double)(fract->mouse.y - fract->mouse.prev_y)
					/ 10000;
			draw_fractal(fract);
		}
	return (0);
}

int		key_press(int key, t_fract *fract)
{
	if (is_arrow(key))
	{
		move_fractal(fract, key);
		if (!draw_fractal(fract))
			error("failed to draw fractal", fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr,
				0, 0);
	}
	return (0);
}
