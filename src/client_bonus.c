/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:17:47 by pclaus            #+#    #+#             */
/*   Updated: 2024/01/25 18:17:48 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/minitalk_bonus.h"
#include "../bonus_includes/client_bonus.h"
#include <stdio.h>

void	handle_signal(int sig)
{
	printf("Signal received!The signal is: %d\n", sig);
	return;
}

void	convert_char_to_bits(int pid, char c)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		if (((c >> count) & 1) == 1)
			//ft_putchar('1');//send kill SIGUSR1
			kill(pid, SIGUSR1);
		if (((c >> count) & 1) == 0)
			//ft_putchar('0'); //send kill SIGUSR2
			kill(pid, SIGUSR2);
		count--;
		usleep(42);
	}

}


int	main(int argc, char *argv[])
{
	char	*pid;
	char	*string;
	int		new_pid;
	int		index;
	
	struct sigaction sa;
	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	index = 0;
	if (argc <= 1)
		return (0);
	pid = argv[1];
	string = argv[2];
	new_pid = ft_atoi(pid);
	while (string[index] != '\0')
		convert_char_to_bits(new_pid, string[index++]);
	if (string[index] == '\0')
		convert_char_to_bits(new_pid, '\0');
	while (1)
		pause();
	return (0);
}
