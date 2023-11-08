/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:58:19 by ahans             #+#    #+#             */
/*   Updated: 2023/11/08 17:19:10 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_int_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_int(unsigned int num, char min_maj)
{
	if (num >= 16)
	{
		ft_put_int(num / 16, min_maj);
		ft_put_int(num % 16, min_maj);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + min_maj), 1);
	}
}

t_flags	arg_x(int num, t_flags *ret, char min_maj)
{
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
		{
			ret->len = -1;
			return (*ret);
		}
		ret->len++;
	}
	else
	{
		ft_put_int(num, min_maj);
		ret->len += ft_int_len(num);
	}
	ret->charac++;
	return (*ret);
}
