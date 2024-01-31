/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:31:53 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 14:33:17 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (s1[index] == s2[index] && s1[index] != '\0')
	{
		if (index < (n - 1))
			index++;
		else
			return (0);
	}
	return ((unsigned char)(s1[index]) - (unsigned char)(s2[index]));
}
