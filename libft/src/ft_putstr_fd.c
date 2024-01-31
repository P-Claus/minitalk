/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:03:01 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 17:03:07 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	if (!s || fd < 0)
		return ;
	index = 0;
	while (s[index] != '\0')
		write(fd, &s[index++], 1);
}
