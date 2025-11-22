/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouassar <aouassar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:17:27 by aouassar          #+#    #+#             */
/*   Updated: 2025/11/22 17:41:20 by aouassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned long nb, char format)
{
	int		count;
	int		digit;
	char	c;

	count = 0;
	if (nb >= 16)
		count += ft_puthex(nb / 16, format);
	digit = nb % 16;
	if (digit < 10)
		c = '0' + digit;
	else
	{
		if (format == 'x')
			c = 'a' + (digit - 10);
		else
			c = 'A' + (digit - 10);
	}
	write(1, &c, 1);
	return (count + 1);
}

int	ft_print_hex(unsigned int n, char format)
{
	int		count;
	long	nb;

	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	nb = n;
	count += ft_puthex(nb, format);
	return (count);
}
