/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:53:53 by pclaus            #+#    #+#             */
/*   Updated: 2024/01/25 10:53:55 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>


void	handle_signal(int sig)
{
	static char	char_received;
	static int		bit_index;

	if (sig == SIGUSR1)
		char_received |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		if (char_received == '\0')
			ft_putchar('\n');
		else
			ft_putchar(char_received);
		bit_index = 0;
		char_received = 0;
	}
	else
		char_received <<= 1;
}

int	main(void)
{
	struct sigaction sa;
	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("The pid is: %d\n", getpid());
	while (1)
		pause();

	return (0);
}
