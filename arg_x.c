/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:58:19 by ahans             #+#    #+#             */
/*   Updated: 2023/11/06 15:53:16 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t num)
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
int	ft_int_len(unsigned int num)
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

void	ft_put_ptr(uintptr_t num, char min_maj)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16, min_maj);
		ft_put_ptr(num % 16, min_maj);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + min_maj), 1);
	}
}

void	ft_put_int(unsigned int num, char min_maj)
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
		ret->len += write(1, "0", 1);
	else
	{
		ft_put_int(num, min_maj);
		ret->len += ft_int_len(num);
	}
	ret->charac++;
	return (*ret);
}

t_flags	arg_p(unsigned long long ptr, t_flags *ret)
{
	ret->len += write(1, "0x", 2);
	if (ptr == 0)
		ret->len += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr, 'a');
		ret->len += ft_ptr_len(ptr);
	}
	ret->charac++;
	return (*ret);
}
