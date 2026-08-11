/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:13:25 by anleclab          #+#    #+#             */
/*   Updated: 2019/03/04 08:46:10 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_rainbow(t_fract *fract)
{
	int		i;

	i = -1;
	while (++i < COL_TAB_SIZE)
		if (i % 5 == 0)
			fract->col_tab[RAINBOW][i] = R_1;
		else if (i % 5 == 1)
			fract->col_tab[RAINBOW][i] = R_2;
		else if (i % 5 == 2)
			fract->col_tab[RAINBOW][i] = R_3;
		else if (i % 5 == 3)
			fract->col_tab[RAINBOW][i] = R_4;
		else
			fract->col_tab[RAINBOW][i] = R_5;
}

static void	init_smooth(t_fract *fract)
{
	int		i;

	i = -1;
	while (++i < COL_TAB_SIZE)
	{
		fract->col_tab[S_BLUE_TO_ORANGE][i] = gradient(((double)i
					/ (double)COL_TAB_SIZE), B2O_1, B2O_5);
		fract->col_tab[FIRE][i] = gradient(((double)i
					/ (double)COL_TAB_SIZE), FIRE_1, FIRE_2);
	}
}

void		init_col_tab(t_fract *fract)
{
	int		i;

	i = -1;
	while (++i < COL_TAB_SIZE)
	{
		fract->col_tab[BLACK_N_WHITE][i] = 0xFFFFFF;
		if (i < COL_TAB_SIZE / 200)
			fract->col_tab[BLUE_TO_ORANGE][i] = B2O_1;
		else if (i < 2 * COL_TAB_SIZE / 200)
			fract->col_tab[BLUE_TO_ORANGE][i] = B2O_2;
		else if (i < 3 * COL_TAB_SIZE / 200)
			fract->col_tab[BLUE_TO_ORANGE][i] = B2O_3;
		else if (i < 4 * COL_TAB_SIZE / 200)
			fract->col_tab[BLUE_TO_ORANGE][i] = B2O_4;
		else
			fract->col_tab[BLUE_TO_ORANGE][i] = B2O_5;
	}
	init_rainbow(fract);
	init_smooth(fract);
}
