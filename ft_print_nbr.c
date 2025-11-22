/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouassar <aouassar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:17:25 by aouassar          #+#    #+#             */
/*   Updated: 2025/11/22 16:01:46 by aouassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(long nb)
{
	char	c;
	int		count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	c = '0' + (nb % 10);
	write(1, &c, 1);
	return(count + 1);
}

int	ft_print_nbr(int n)
{
	long	nb;
	int		count;
	
	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		count++;
		nb = -nb;
	}
	count += ft_putnbr(nb);
	return (count);
}
