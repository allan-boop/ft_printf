/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:02:03 by ahans             #+#    #+#             */
/*   Updated: 2023/10/20 10:08:01 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int charac)
{
	if ((charac >= 'A' && charac <= 'Z') || (charac >= 'a' && charac <= 'z'))
	{
		return (charac);
	}
	return (0);
}
