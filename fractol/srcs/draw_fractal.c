/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:45:08 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/27 15:57:29 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	max_it(int iter)
{
	if (iter >= COL_TAB_SIZE)
		return (COL_TAB_SIZE - 1);
	else if (iter < 0)
		return (0);
	else
		return (iter);
}

static void	put_pixel(t_fract *fract, int x, int y, t_felem elem)
{
	int		glow;

	glow = (fract->color == S_BLUE_TO_ORANGE) ? 100 : 10;
	if (elem.exit >= ITERATIONS)
		return ;
	if (fract->color == BLACK_N_WHITE || fract->color == BLUE_TO_ORANGE
			|| fract->color == RAINBOW)
		fract->addr[x + y * fract->width] = fract->col_tab[fract->color]
				[max_it(elem.exit)];
	else
		fract->addr[x + y * fract->width] = fract->col_tab[fract->color]
				[max_it((int)(glow * ((double)elem.exit
				- log2(log2(sqrt(c_sqmod(elem.val)))))))];
}

static void	*draw_fract_thread(void *thread_param)
{
	int				x;
	int				y;
	t_felem			elem;
	int				max;
	t_thread_param	p;

	p = *(t_thread_param *)thread_param;
	y = p.id * (p.fract->height / NB_THREADS) - 1;
	max = y + p.fract->height / NB_THREADS + 1;
	max += (p.id == NB_THREADS - 1) ? p.fract->height % NB_THREADS : 0;
	while (++y < max && (x = -1))
		while (++x < p.fract->width)
		{
			if (p.fract->name == MANDELBROT)
				elem = iter_mandelbrot(coord(p.fract, x, y));
			else if (p.fract->name == JULIA)
				elem = iter_julia(p.fract, coord(p.fract, x, y));
			else if (p.fract->name == BURNING_SHIP)
				elem = iter_burning_ship(coord(p.fract, x, y));
			put_pixel(p.fract, x, y, elem);
		}
	return (NULL);
}

int			draw_fractal(t_fract *fract)
{
	int				i;
	t_thread_param	thread_param[NB_THREADS];
	pthread_t		thread[NB_THREADS];
	int				res;

	ft_bzero(fract->addr, fract->width * fract->height * 4);
	i = -1;
	res = 0;
	while (++i < NB_THREADS && !res)
	{
		thread_param[i].id = i;
		thread_param[i].fract = fract;
		res = pthread_create(thread + i, NULL, &draw_fract_thread,
					(void *)(thread_param + i));
	}
	while (--i >= 0)
		pthread_join(thread[i], NULL);
	if (res)
		return (0);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0,
			0);
	return (1);
}
