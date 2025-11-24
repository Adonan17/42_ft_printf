/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouassar <aouassar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:17:22 by aouassar          #+#    #+#             */
/*   Updated: 2025/11/24 14:56:01 by aouassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_hex(unsigned long long nb)
{
	int		count;
	int		digit;
	char	c;

	count = 0;
	if (nb >= 16)
		count += ft_ptr_hex(nb / 16);
	digit = nb % 16;
	if (digit < 10)
		c = '0' + digit;
	else
		c = 'a' + (digit - 10);
	write(1, &c, 1);
	return (count + 1);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	count;

	write(1, "0x", 2);
	count = 2;
	if (ptr == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	count += ft_ptr_hex(ptr);
	return (count);
}
