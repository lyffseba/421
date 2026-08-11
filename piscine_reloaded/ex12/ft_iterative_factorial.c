/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:57:56 by anleclab          #+#    #+#             */
/*   Updated: 2018/11/05 16:06:45 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		res;

	res = 1;
	if (nb > 12 || nb < 0)
		return (0);
	else
	{
		while (nb > 0)
		{
			res *= nb;
			nb--;
		}
		return (res);
	}
}
