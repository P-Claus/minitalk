/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_void_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:02:24 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/21 22:21:32 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	put_void_pointer(unsigned long n, unsigned int base)
{
	if (n == 0)
		return (write(1, "(nil)", 5));
	else
	{
		write(1, "0x", 2);
		return (print_void_pointer(n, base) + 2);
	}
}

int	print_void_pointer(unsigned long n, unsigned int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < base)
		return (print_character(symbols[n]));
	else
	{
		count += print_void_pointer((n / base), base);
		return (count + print_void_pointer((n % base), base));
	}
}
