/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:01:03 by ahans             #+#    #+#             */
/*   Updated: 2023/11/08 17:16:11 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, t_flags *ret)
{
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		ret->len += 6;
		return (0);
	}
	while (*str)
	{
		if (write(1, str, 1) == -1)
			return (-1);
		str++;
		ret->len++;
	}
	return (0);
}
