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

void	handle_signal(int sig)
{
	(void)sig;
	ft_putstr_color_fd(ANSI_COLOR_BLUE, "The message has been received\n", 1);
	exit(1);
}

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
		usleep(42);
	}

}

int	main(int argc, char *argv[])
{
	char	*string;
	int		index;
	
	struct sigaction sa;
	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	index = 0;
	if (argc <= 1)
		return (0);
	if (argc != 3)
	{
		ft_putstr_color_fd(ANSI_COLOR_RED, "Invalid arguments\n", 2);
		ft_putstr_fd("The correct format is: ", 1);
		ft_putstr_color_fd(ANSI_COLOR_YELLOW, "./client_bonus <PID> <STRING>\n", 1);
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
