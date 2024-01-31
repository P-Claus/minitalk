/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:58:08 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 16:58:32 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		digits;
	long int	num;

	num = n;
	digits = count_digits(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	str = (char *)malloc(sizeof(char) * digits + 1);
	if (!str)
		return (NULL);
	*(str + digits) = 0;
	while (digits--)
	{
		*(str + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
