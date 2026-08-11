/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 11:39:22 by anleclab          #+#    #+#             */
/*   Updated: 2019/01/23 14:09:16 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*init_base(int base)
{
	char	*charbase;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	if (!(charbase = ft_strnew(base + 1)))
		return (NULL);
	i = 0;
	while (i < base && i < 10)
	{
		charbase[i] = (char)('0' + i);
		i++;
	}
	while (i < base)
	{
		charbase[i] = (char)(i - 10 + 'a');
		i++;
	}
	return (charbase);
}

static int	nb_digits(unsigned int nb, int base)
{
	int		nbdigits;

	nbdigits = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nbdigits++;
		nb /= (unsigned int)base;
	}
	return (nbdigits);
}

char		*ft_itoa_base(int n, int base)
{
	char			*charbase;
	char			*res;
	unsigned int	nb;
	int				nbdigits;
	int				i;

	if (!(charbase = init_base(base)))
		return (NULL);
	nb = (n < 0) ? (unsigned int)(-n) : (unsigned int)n;
	nbdigits = nb_digits(nb, base);
	if (!(res = ft_strnew((size_t)nbdigits)))
		return (NULL);
	i = -1;
	while (++i < nbdigits)
	{
		res[nbdigits - 1 - i] = charbase[nb % (unsigned int)base];
		nb /= (unsigned int)base;
	}
	free(charbase);
	return (res);
}
