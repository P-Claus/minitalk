/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:19:32 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 15:20:20 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int	iter;
	int	sign;
	int	result;

	iter = 0;
	sign = 1;
	result = 0;
	while (str[iter] && ((str[iter] >= 9 && str[iter] <= 13) || \
				str[iter] == 32))
		iter++;
	if (str[iter] == '+' || str[iter] == '-')
	{
		if (str[iter] == '-')
			sign = -1;
		iter++;
	}
	while (str[iter] >= '0' && str[iter] <= '9' && str[iter] != '\0')
	{
		result = result * 10 + str[iter] - '0';
		iter++;
	}
	return (result * sign);
}
