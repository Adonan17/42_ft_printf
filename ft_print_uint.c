/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouassar <aouassar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:17:16 by aouassar          #+#    #+#             */
/*   Updated: 2025/11/30 17:50:45 by aouassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putunbr(unsigned long nb)
{
	char	c;
	int		count;

	count = 0;
	if (nb >= 10)
		count += ft_putunbr(nb / 10);
	c = '0' + (nb % 10);
	write(1, &c, 1);
	return (count + 1);
}

int	ft_print_uint(unsigned int n)
{
	long	nb;
	int		count;

	count = 0;
	nb = n;
	count += ft_putunbr(nb);
	return (count);
}
