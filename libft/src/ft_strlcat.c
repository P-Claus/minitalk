/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:20:29 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 14:28:49 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_index;
	size_t	src_index;

	dst_index = 0;
	src_index = 0;
	while (dst[dst_index] && dst_index < size)
		dst_index++;
	while (src[src_index] && (dst_index + src_index + 1) < size)
	{
		dst[dst_index + src_index] = src[src_index];
		src_index++;
	}
	if (dst_index < size)
		dst[dst_index + src_index] = '\0';
	return (dst_index + ft_strlen(src));
}
