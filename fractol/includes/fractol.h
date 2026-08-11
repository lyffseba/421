/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:25:34 by anleclab          #+#    #+#             */
/*   Updated: 2019/03/04 15:45:46 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "keys.h"
# include "colors.h"
# include <math.h>
# include <pthread.h>

# define SIZE 250
# define ITERATIONS 100
# define COL_TAB_SIZE 1000
# define NB_COLOR_SCHEMES 5
# define NB_THREADS 20

# define EXIT_ERROR 1
# define EXIT_OK 0

typedef struct	s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct	s_felem
{
	t_point	val;
	int		exit;
}				t_felem;

typedef enum	e_name
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP,
	NONE
}				t_name;

typedef enum	e_color
{
	BLACK_N_WHITE,
	BLUE_TO_ORANGE,
	RAINBOW,
	S_BLUE_TO_ORANGE,
	FIRE
}				t_color;

typedef enum	e_mode
{
	ZOOM,
	COLOR
}				t_mode;

typedef struct	s_image
{
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_mouse
{
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
}				t_mouse;

typedef struct	s_fract
{
	t_name			name;
	int				width;
	int				is_active_mouse;
	int				height;
	t_color			color;
	t_mouse			mouse;
	int				col_tab[NB_COLOR_SCHEMES][1000];
	double			zoom;
	t_mode			mode;
	t_point			julia;
	double			x_offset;
	double			y_offset;
	unsigned int	*addr;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_image			image;
}				t_fract;

typedef struct	s_thread_param
{
	int			id;
	t_fract		*fract;
}				t_thread_param;

t_name			which_fractal(char *str);
int				draw_fractal(t_fract *fract);
void			end(t_fract *fract, int end_status);
void			error(char *str, t_fract *fract);

int				mouse_event(int button, int x, int y, t_fract *fract);
int				close_win(t_fract *fract);
int				key_release(int key, t_fract *fract);
int				key_press(int key, t_fract *fract);
int				mouse_move(int x, int y, t_fract *fract);
int				is_arrow(int key);
int				is_letter_direction(int key);
void			change_julia_param(t_fract *fract, int key);
void			move_fractal(t_fract *fract, int key);
void			zoom(t_fract *fract, int key, t_point tmp);

t_point			coord(t_fract *fract, int x, int y);

void			init_col_tab(t_fract *fract);
int				gradient(double ratio, int start, int end);
double			ratio(int start, int end, int current);

t_felem			iter_mandelbrot(t_point c);
t_felem			iter_burning_ship(t_point c);
t_felem			iter_julia(t_fract *fract, t_point c);

int				new_image(t_fract *fract);

t_point			c_add(t_point a, t_point b);
t_point			c_mult(t_point a, t_point b);
t_point			c_sq(t_point a);
double			c_sqmod(t_point a);

#endif
