/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:44:13 by ahans             #+#    #+#             */
/*   Updated: 2023/11/01 17:25:16 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg_type(const char *charac)
{
	if(charac++ == 'c')
		return ((int)'c');
	else if (charac++ == 's')
		return ((int)'s');
	else if (charac++ == 'p')
		return ((int)'p');
	else if (charac++ == 'd')
		return ((int)'d');
	else if (charac++ == 'i')
		return ((int)'i');
	else if (charac++ == 'u')
		return ((int)'u');
	else if (charac++ == 'x')
		return ((int)'x');
	else if (charac++ == 'X')
		return ((int)'X');
	else if (charac++ =='%')
		return ((int)'%');
	else
		return (0);
}

int	arg_c(va_list arg)
{
	write(1, va_arg(arg, char) , 1);
	return (1);
}

int arg_s(va_list arg)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(arg, char *);
	while(str++)
	{
		write(1, &str, 1);
		i++;
	}
	return (i);
}

int arg_p(va_list arg)
{

}

int arg_d(va_list arg)
{
	ft_putnbr_fd(1, va_arg(arg, int));
}

int	arg_parser(va_list arg, char type)
{
	if (type == 'c')
		return (arg_c(arg));
	else if (type == 's')
		return (arg_s(arg));
	else if (type == 'p')
		return (arg_p(arg));
	else if (type == 'd')
		return (arg_d(arg));
}

int	check_charac(const char *charac, va_list args, flags *ret)
{
	int i;

	i = 0;
	while (charac++)
	{
		if(charac == '%' && check_arg(charac) > 0)
		{
			i += arg_parser(args, check_arg_type(charac));
			charac++;
		}
		write(1, &charac, 1);
		i++;
	}
	va_end(args);
	return (ret->i);
}

int	ft_printf(const char *format, ...)
{
	flags	*ret;
	va_list args;
	va_start(args, format);

	ret = malloc(sizeof(flags));
	ret->i = 0;
	ret->err = 0;
	return(check_charac(format, args, ret));
}