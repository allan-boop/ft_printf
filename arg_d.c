/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:04:33 by ahans             #+#    #+#             */
/*   Updated: 2023/11/08 17:07:14 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	arg_d(va_list arg, t_flags *ret)
{
	char	*str;

	str = ft_itoa(va_arg(arg, int));
	if (ft_putstr(str, ret) == -1)
		ret->len = -1;
	ret->charac++;
	free(str);
	return (*ret);
}
