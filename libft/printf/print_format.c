/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:07:47 by pclaus            #+#    #+#             */
/*   Updated: 2023/12/05 19:29:48 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_character(va_arg(ap, int));
	else if (specifier == 's')
		count += print_string(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'u')
		count += print_unsigned_int((long)(va_arg(ap, int)), 10);
	else if (specifier == 'x')
		count += print_hex_lower((long)(va_arg(ap, unsigned int)), 16);
	else if (specifier == 'X')
		count += print_hex_upper((long)(va_arg(ap, unsigned int)), 16);
	else if (specifier == 'p')
		count += put_void_pointer((unsigned long)(va_arg(ap, void *)), 16);
	else
		count += print_character('%');
	return (count);
}
