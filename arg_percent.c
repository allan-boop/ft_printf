/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:29:41 by ahans             #+#    #+#             */
/*   Updated: 2023/11/06 13:43:25 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	arg_percent(t_flags *ret)
{
	ret->charac++;
	ret->charac++;
	write(1, "%", 1);
	ret->len++;
	return (*ret);
}