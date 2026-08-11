/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_functions_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:56:09 by anleclab          #+#    #+#             */
/*   Updated: 2019/05/06 16:25:47 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	*conv_c_wchar(va_list *ap)
{
	wint_t			c;
	unsigned char	*res;

	c = va_arg(*ap, wint_t);
	res = ft_wchar_to_bytes(c);
	return (res);
}

static unsigned char	*conv_s_wchar(va_list *ap)
{
	wchar_t			*arg;
	unsigned char	*res;
	int				i;

	arg = va_arg(*ap, wchar_t *);
	i = 0;
	if (!(res = (unsigned char *)ft_strnew(1)))
		exit_error("error: malloc failed\n", 0);
	while (arg[i])
	{
		res = concatenate(res, ft_wchar_to_bytes(arg[i]));
		i++;
	}
	return (res);
}

char					*conv_p(va_list *ap, char *mod)
{
	void	*str;
	char	*res;
	char	*conv;

	(void)mod;
	str = va_arg(*ap, void *);
	conv = ft_llitoa_base((unsigned long)str, 16);
	if (!conv)
		exit_error("error: malloc failed\n", 0);
	if (!(res = ft_strjoin("0x", conv)))
		exit_error("error: malloc failed\n", 1, conv);
	free(conv);
	return (res);
}

char					*conv_c(va_list *ap, char *mod)
{
	char			*res;
	unsigned char	arg;

	if (ft_strequ(mod, "l"))
		res = (char *)conv_c_wchar(ap);
	else
	{
		arg = (unsigned char)va_arg(*ap, int);
		if (!(res = ft_strnew(1)))
			exit_error("error: malloc_failed\n", 0);
		res[0] = arg;
	}
	return (res);
}

char					*conv_s(va_list *ap, char *mod)
{
	char	*res;

	if (ft_strequ(mod, "l"))
		res = (char *)conv_s_wchar(ap);
	else
	{
		res = (char *)va_arg(*ap, const char *);
		if (!res)
		{
			if (!(res = ft_strdup("(null)")))
				exit_error("error: malloc failed\n", 0);
			return (res);
		}
		if (!(res = ft_strdup(res)))
			exit_error("error: malloc failed\n", 0);
	}
	return (res);
}
