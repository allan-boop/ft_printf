/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:58:19 by ahans             #+#    #+#             */
/*   Updated: 2023/11/04 13:58:22 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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