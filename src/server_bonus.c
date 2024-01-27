/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:17:58 by pclaus            #+#    #+#             */
/*   Updated: 2024/01/25 18:18:00 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/minitalk_bonus.h"
#include "../bonus_includes/server_bonus.h"
#include <stdio.h>

void	send_confirmation_and_print_char(char char_received, int pid)
{
	if (char_received == '\0')
	{
		ft_putchar('\n');
		kill(pid, SIGUSR1);
	}
	else
		ft_putchar(char_received);
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	char_received;
	static int	bit_index;
	static int	pid;

	(void) context;
	if (pid == 0)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		bit_index = 0;
		char_received = 0;
		pid = 0;
	}
	if (sig == SIGUSR1)
		char_received |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		send_confirmation_and_print_char(char_received, pid);
		bit_index = 0;
		char_received = 0;
	}
	else
		char_received <<= 1;
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			block_signals;

	sigemptyset(&block_signals);
	sigaddset(&block_signals, SIGINT);
	sigaddset(&block_signals, SIGQUIT);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = block_signals;
	sa.sa_sigaction = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("The PID is: ", 1);
	ft_putstr_color_fd(YELLOW, ft_itoa(getpid()), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}
