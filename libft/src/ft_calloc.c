/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:20:51 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 15:23:56 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*ptr;
	size_t	counter;
	size_t	total_size;

	counter = 0;
	total_size = num_elements * element_size;
	if (num_elements != 0 && element_size != 0 \
			&& total_size / num_elements != element_size)
		return (0);
	ptr = malloc(total_size);
	if (ptr == 0)
		return (0);
	while (counter < total_size)
	{
		((char *) ptr)[counter] = 0;
		counter++;
	}
	return (ptr);
}
