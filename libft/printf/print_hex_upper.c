/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:17:34 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/18 16:02:55 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_hex_upper(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789ABCDEF";
	if (n < base)
		return (print_character(symbols[n]));
	else
	{
		count += print_hex_upper((n / base), base);
		return (count + print_hex_upper((n % base), base));
	}
}
