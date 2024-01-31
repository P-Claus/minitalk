/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:41:06 by pclaus            #+#    #+#             */
/*   Updated: 2023/10/31 19:41:23 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[h])
	{
		n = 0;
		while (haystack[h] == needle[n] && haystack[h] && h < len)
		{
			h++;
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)&haystack[h - n]);
		h = (h - n) + 1;
	}
	return (0);
}
