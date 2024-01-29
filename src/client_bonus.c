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

int	received_signal;

void	handle_signal(int sig)
{
	(void)sig;
	if (sig == SIGUSR1)
	{
		ft_putstr_color_fd(YELLOW, "The bit has been received\n", 1);
		received_signal = 1;
	}
	else if (sig == SIGUSR2)
	{
		ft_putstr_color_fd(BLUE, "The message has been received\n", 1);
		received_signal = 0;
		exit(0);
	}
}
/*
void	send_first_bit(int pid, char c)
{
	if (((c >> 7) & 1) == 1)
		kill(pid, SIGUSR1);
	if (((c >> 7) & 1) == 0)
		kill(pid, SIGUSR2);
}
*/
void	convert_char_to_bits(int pid, char c)
{
	int	count;

	count = 7;
	while (count >= 0 && received_signal == 1)
	{
		if (((c >> count) & 1) == 1)
			kill(pid, SIGUSR1);
		if (((c >> count) & 1) == 0)
			kill(pid, SIGUSR2);
		count--;
		received_signal = 0;
		pause();
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	char				*string;
	int					index;

	received_signal = 1;
	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	index = 0;
	if (argc <= 1)
		return (0);
	if (argc != 3)
	{
		ft_putstr_color_fd(RED, "Invalid arguments\n", 2);
		ft_putstr_fd("The correct format is: ", 1);
		ft_putstr_color_fd(YELLOW, "./client_bonus <PID> <STRING>\n", 1);
		exit(1);
	}
	string = argv[2];
	while (string[index] != '\0')
		convert_char_to_bits(ft_atoi(argv[1]), string[index++]);
	if (string[index] == '\0')
		convert_char_to_bits(ft_atoi(argv[1]), '\0');
	while (1)
		pause();
	return (0);
}
