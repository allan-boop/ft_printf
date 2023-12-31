/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:01:50 by ahans             #+#    #+#             */
/*   Updated: 2023/10/18 16:46:52 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int charac)
{
	if ((charac < 48 || charac > 122)
		|| (charac > 57 && charac < 65) || (charac > 90 && charac < 97))
	{
		return (0);
	}
	return (1);
}
