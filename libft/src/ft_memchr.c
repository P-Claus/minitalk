/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:33:28 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 14:39:10 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*str;
	unsigned char	character;

	str = (unsigned char *) s;
	character = (unsigned char) c;
	index = 0;
	while (index < n)
	{
		if (*str == character)
			return ((void *)(str));
		index++;
		str++;
	}
	return (0);
}
