/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:44:28 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 14:45:45 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	int		counter;
	char	*dst;

	len = ft_strlen(src) + 1;
	counter = 0;
	dst = (char *) malloc(len * sizeof(char));
	if (dst == 0)
		return (0);
	while (*(src + counter) != '\0')
	{
		*(dst + counter) = *(src + counter);
		counter++;
	}
	*(dst + counter) = '\0';
	return (dst);
}
