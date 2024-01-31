/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:16:50 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 14:20:19 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[len] != '\0' && len < dstsize - 1)
	{
		dst[len] = src[len];
		len++;
	}
	if (len < dstsize)
		dst[len] = '\0';
	while (src[len] != '\0')
		len++;
	return (len);
}
