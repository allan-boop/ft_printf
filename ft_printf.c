/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:44:13 by ahans             #+#    #+#             */
/*   Updated: 2023/11/08 10:49:50 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	check_arg_type(va_list arg, t_flags *ret)
{
	ret->charac++;
	if (*ret->charac == 'c')
		return (arg_c(arg, ret));
	else if (*ret->charac == 's')
		return (arg_s(arg, ret));
	else if (*ret->charac == 'p')
		return (arg_p(va_arg(arg, unsigned long long), ret));
	else if (*ret->charac == 'd' || *ret->charac == 'i')
		return (arg_d(arg, ret));
	else if (*ret->charac == 'x')
		return (arg_x(va_arg(arg, int), ret, 'a'));
	else if (*ret->charac == 'X')
		return (arg_x(va_arg(arg, int), ret, 'A'));
	else if (*ret->charac == '%')
		return (arg_percent(ret));
	else if (*ret->charac == 'u')
		return (arg_u(va_arg(arg, unsigned int), ret));
	else
	{
		ret->len += write(1, "%", 1);
		return (*ret);
	}
}

static int	check_charac(va_list args, t_flags *ret)
{
	while (*ret->charac)
	{
		if (*ret->charac == '%')
			check_arg_type(args, ret);
		else if (*ret->charac)
		{
			if (write(1, ret->charac, 1) == -1)
				return (-1);
			ret->len++;
			ret->charac++;
		}
	}
	va_end(args);
	return (ret->len);
}

int	ft_printf(const char *format, ...)
{
	t_flags	*ret;
	int		leng;
	va_list	args;

	va_start(args, format);
	ret = malloc(sizeof(t_flags));
	ret->len = 0;
	ret->charac = format;
	ret->err = 0;
	leng = check_charac(args, ret);
	free(ret);
	return (leng);
}
