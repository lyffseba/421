/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <anleclab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 11:39:22 by anleclab          #+#    #+#             */
/*   Updated: 2019/07/03 14:55:09 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_base(char *base)
{
	int		i;

	i = -1;
	while (++i < 10)
		base[i] = (char)('0' + i);
	while (i < 16)
	{
		base[i] = (char)(i - 10 + 'a');
		i++;
	}
	base[16] = 0;
}

static int	nb_digits(unsigned long long nb, int base)
{
	int		nbdigits;

	if (base < 2)
		return (-1);
	if (nb == 0)
		return (1);
	nbdigits = 0;
	while (nb)
	{
		nbdigits++;
		nb /= (unsigned long long)base;
	}
	return (nbdigits);
}

char		*ft_llitoa_base(unsigned long long n, int base)
{
	char	charbase[17];
	char	*res;
	int		nbdigits;

	if (base < 2 || base > 16)
		return (NULL);
	init_base(charbase);
	nbdigits = nb_digits(n, base);
	if (!(res = ft_strnew((size_t)nbdigits)))
		return (NULL);
	while (nbdigits--)
	{
		res[nbdigits] = charbase[n % (unsigned long long)base];
		n /= (unsigned long long)base;
	}
	return (res);
}
