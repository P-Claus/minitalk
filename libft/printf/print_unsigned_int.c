/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:05:28 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/18 16:04:36 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_unsigned_int(long n, int base)
{
	if (n < 0)
		return (print_digit((n + 1 + 4294967295), base));
	else
		return (print_digit(n, base));
}
