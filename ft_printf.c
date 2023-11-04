/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:44:13 by ahans             #+#    #+#             */
/*   Updated: 2023/11/04 15:00:58 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg_type(const char *charac)
{
	charac++;
	if(*charac == 'c')
		return ((int)'c');
	else if (*charac == 's')
		return ((int)'s');
	else if (*charac == 'p')
		return ((int)'p');
	else if (*charac == 'd' || *charac == 'i')
		return ((int)'d');
	else if (*charac == 'u')
		return ((int)'u');
	else if (*charac == 'x')
		return ((int)'x');
	else if (*charac == 'X')
		return ((int)'X');
	else if (*charac =='%')
		return ((int)'%');
	else
		return (0);
}

t_flags	arg_parser(va_list arg, char type, t_flags *ret)
{
	if (type == 'c')
	{
		ret->charac++;
		return (arg_c(arg, ret));
	}
	else if (type == 's')
	{
		ret->charac++;
		return (arg_s(arg, ret));
	}
	else if (type == 'p')
	{
		ret->charac++;
		return (arg_p(arg, ret));
	}
	else if (type == 'x')
	{
		ret->charac++;
		return (arg_x(arg, ret, 'a'));
	}
	else if (type == 'x')
	{
		ret->charac++;
		return (arg_x(arg, ret, 'A'));
	}
	else if (type == 'd' || type == 'u')
	{
		ret->charac++;
		return (arg_d(arg, ret));
	}
	else if (type == '%')
	{
		ret->charac++;
		ret->charac++;
		write(1, "%", 1);
		ret->len++;
		return (*ret);
	}
	return(*ret);
}

int	check_charac(va_list args, t_flags *ret)
{
	while (*ret->charac)
	{
		if(*ret->charac == '%' && check_arg_type(ret->charac) > 0)
			arg_parser(args, check_arg_type(ret->charac), ret);
		if(*ret->charac)
		{
			write(1, ret->charac, 1);
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
	va_list args;

	va_start(args, format);
	ret = malloc(sizeof(t_flags));
	ret->len = 0;
	ret->charac = format;
	ret->err = 0;
	leng = check_charac(args, ret);
	free(ret);
	return(leng);
}