/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:04:33 by ahans             #+#    #+#             */
/*   Updated: 2023/11/06 14:06:23 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags arg_d(va_list arg, t_flags *ret)
{
	char	*str = ft_itoa(va_arg(arg, int));
	ft_putstr(str, ret);
	ret->charac++;
	free(str);
	return (*ret);
}