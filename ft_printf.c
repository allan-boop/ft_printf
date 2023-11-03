/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:44:13 by ahans             #+#    #+#             */
/*   Updated: 2023/11/03 17:08:22 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	ft_putstr(char *str, t_flags *ret)
{
	if(!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	while(*str)
	{
		write(1, str, 1);
		str++;
		ret->len++;
	}
}

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

t_flags	arg_c(va_list arg, t_flags *ret)
{
	char	f;

	f = va_arg(arg, int);
	write(1, &f, 1);
	ret->charac++;
	ret->len++;
	return (*ret);
}

t_flags arg_s(va_list arg, t_flags *ret)
{
	ft_putstr(va_arg(arg, char *), ret);
	ret->charac++;
	return (*ret);
}

t_flags	arg_x(va_list arg, t_flags *ret, char min_maj)
{
    char hexadecimal[10];
    int index = 0;
	int decimalNumber;
    int i, j;
    char temp;
	int remainder;

	decimalNumber = va_arg(arg, int);
    while (decimalNumber > 0)
	{
        remainder = decimalNumber % 16;
        if (remainder < 10)
            hexadecimal[index] = remainder + '0';
    	else
            hexadecimal[index] = remainder - 10 + min_maj;
        decimalNumber /= 16;
        index++;
    }
    hexadecimal[index] = '\0';
	i = 0;
	j = index - 1;
    while (i < j) 
	{
        temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[j];
        hexadecimal[j] = temp;
        i++;
        j--;
    }
	ft_putstr(hexadecimal, ret);
	ret->charac++;
	return (*ret);
}

t_flags arg_p(va_list arg, t_flags *ret)
{
    unsigned long decimalNumber = (unsigned long)va_arg(arg, long);
    unsigned long temp = decimalNumber;
    int numDigits = 0;
    while (temp > 0) {
        temp /= 16;
        numDigits++;
    }
    char *hexadecimal = (char *)malloc(numDigits + 1);
    if (hexadecimal == NULL) {
    }
    int index = numDigits;
    while (decimalNumber > 0) {
        int remainder = decimalNumber % 16;
        if (remainder < 10)
            hexadecimal[--index] = remainder + '0';
        else
            hexadecimal[--index] = remainder - 10 + 'a';
        decimalNumber /= 16;
    }
    hexadecimal[numDigits] = '\0';
    ft_putstr(hexadecimal, ret);
    ret->charac++;
    free(hexadecimal);
    return *ret;
}
t_flags arg_d(va_list arg, t_flags *ret)
{
	ft_putstr(ft_itoa(va_arg(arg, int)), ret);
	ret->charac++;
	return (*ret);
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
		{
			arg_parser(args, check_arg_type(ret->charac), ret);
		}
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