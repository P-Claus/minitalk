/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:10:59 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 14:12:53 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	counter;

	counter = 0;
	if (!dest && !src)
		return (0);
	while (counter < n)
	{
		*(unsigned char *)(dest + counter) = *(unsigned char *)(src + counter);
		counter++;
	}
	return (dest);
}
