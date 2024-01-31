/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:04:36 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 17:04:42 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
		write(fd, &s[counter++], 1);
	write (fd, "\n", 1);
}
