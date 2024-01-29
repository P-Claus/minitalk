/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:53:30 by pclaus            #+#    #+#             */
/*   Updated: 2024/01/25 10:53:49 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../includes/client.h"

void	convert_char_to_bits(int pid, char c)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		if (((c >> count) & 1) == 1)
			kill(pid, SIGUSR1);
		if (((c >> count) & 1) == 0)
			kill(pid, SIGUSR2);
		count--;
		usleep(500);
	}
}

int	main(int argc, char *argv[])
{
	char	*string;
	int		index;

	index = 0;
	if (argc <= 1)
		return (0);
	if (argc != 3)
	{
		ft_putstr_color_fd(RED, "Invalid arguments\n", 2);
		ft_putstr_fd("The correct format is: ", 1);
		ft_putstr_color_fd(YELLOW, "./client <PID> <STRING>\n", 1);
		exit(1);
	}
	string = argv[2];
	while (string[index] != '\0')
		convert_char_to_bits(ft_atoi(argv[1]), string[index++]);
	if (string[index] == '\0')
		convert_char_to_bits(ft_atoi(argv[1]), '\0');
	return (0);
}
