/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:28:53 by anleclab          #+#    #+#             */
/*   Updated: 2019/03/04 15:46:38 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage(void)
{
	ft_putstr("usage: ./fractol fractal_name\n");
	ft_putstr("Available fractals: [mandelbrot/man] [julia/jul]");
	ft_putstr(" [burning ship/burn]\n");
}

static void	fract_init_size(t_fract *fract)
{
	if (fract->name == MANDELBROT)
	{
		fract->width = 3 * SIZE;
		fract->height = 2 * SIZE;
	}
	else if (fract->name == JULIA)
	{
		fract->width = 2 * SIZE;
		fract->height = 2 * SIZE;
	}
	else if (fract->name == BURNING_SHIP)
	{
		fract->width = 3 * SIZE;
		fract->height = 3 * SIZE;
	}
}

static void	fract_init(t_fract *fract)
{
	fract->color = BLACK_N_WHITE;
	init_col_tab(fract);
	fract->zoom = 1.0;
	fract->mode = ZOOM;
	fract->addr = NULL;
	fract->mlx_ptr = NULL;
	fract->win_ptr = NULL;
	fract->img_ptr = NULL;
	fract->julia.x = 0.3;
	fract->julia.y = 0.5;
	fract->is_active_mouse = 1;
	fract->mouse.x = 0;
	fract->mouse.y = 0;
	fract_init_size(fract);
	fract->x_offset = 0;
	fract->y_offset = 0;
}

static void	print_controls(void)
{
	ft_putstr("\n//////////////////////// CONTROLS ////////////////////////\n");
	ft_putstr("\n  \033[0;33mchange mode\033[0m: C\n");
	ft_putstr("  \033[0;33mzoom\033[0m: scroll up/down (in zoom mode)\n");
	ft_putstr("  \033[0;33mcolor\033[0m: SPACE / scroll up/down (in color ");
	ft_putstr("mode)\n");
	ft_putstr("  \033[0;33mmove fractal\033[0m: up/down/left/right arrows\n");
	ft_putstr("  \033[0;33mchange julia parameters\033[0m: move ");
	ft_putstr("mouse (if active)\n");
	ft_putstr("  \033[0;33mactivate/deactivate mouse\033[0m: M\n");
	ft_putstr("  \033[0;33mexit\033[0m: ESC / red cross\n\n");
	ft_putstr("//////////////////////////////////////////////////////////\n\n");
}

int			main(int ac, char **av)
{
	t_fract		fract;

	if (ac != 2 || (fract.name = which_fractal(av[1])) == NONE)
	{
		usage();
		exit(0);
	}
	fract_init(&fract);
	if (!(fract.mlx_ptr = mlx_init()))
		error("failed to initialize mlx connection", &fract);
	if (!(fract.win_ptr = mlx_new_window(fract.mlx_ptr, fract.width,
					fract.height, av[1])))
		error("mlx failure", &fract);
	if (!new_image(&fract))
		error("filed to create image", &fract);
	if (!draw_fractal(&fract))
		error("failed to draw fractal", &fract);
	print_controls();
	mlx_hook(fract.win_ptr, 4, 0, &mouse_event, &fract);
	mlx_hook(fract.win_ptr, 17, 0, &close_win, &fract);
	mlx_hook(fract.win_ptr, 3, 0, &key_release, &fract);
	mlx_hook(fract.win_ptr, 6, 0, &mouse_move, &fract);
	mlx_hook(fract.win_ptr, 2, 0, &key_press, &fract);
	mlx_loop(fract.mlx_ptr);
}
