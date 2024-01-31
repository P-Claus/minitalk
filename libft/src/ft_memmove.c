/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:14:18 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 14:16:39 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	counter;

	if (!dst && !src)
		return (0);
	if (src < dst)
	{
		counter = len;
		while (counter > 0)
		{
			counter--;
			*(unsigned char *)(dst + counter) = \
				*(unsigned char *)(src + counter);
		}
	}
	else
	{
		counter = 0;
		while (counter < len)
		{
			*(unsigned char *)(dst + counter) = \
				*(unsigned char *)(src + counter);
			counter++;
		}
	}
	return (dst);
}
