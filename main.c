/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:44:27 by ahans             #+#    #+#             */
/*   Updated: 2023/11/04 12:50:07 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int f = 12656;
	fflush(stdout);
	printf("og NULL %s NULL \n", NULL);
	fflush(stdout);
	ft_printf("ft NULL %s NULL \n", NULL);
	fflush(stdout);

	return (0);
}