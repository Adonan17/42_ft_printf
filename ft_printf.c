/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouassar <aouassar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:17:13 by aouassar          #+#    #+#             */
/*   Updated: 2025/11/30 17:51:50 by aouassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list *args, char specifier)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(*args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	else if (specifier == 'u')
		return (ft_print_uint(va_arg(*args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), specifier));
	else if (specifier == 'p')
		return (ft_print_ptr((unsigned long long)va_arg(*args, void *)));
	else if (specifier == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else if (format[i + 1] != '\0')
		{
			count += ft_formats(args, format[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
