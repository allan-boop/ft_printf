/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:02:16 by ahans             #+#    #+#             */
/*   Updated: 2023/11/04 14:03:03 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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