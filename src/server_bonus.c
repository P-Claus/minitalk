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

void	send_confirmation_and_print_char(char char_received, int pid)
{
	if (char_received != '\0')
		ft_putchar(char_received);
	else
	{
		ft_putchar('\n');
		kill(pid, SIGUSR2);
	}
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	char_received = 0;
	static int	bit_index = 0;
	static int	pid = 0;

	(void) context;
	if (pid == 0)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		bit_index = 0;
		char_received = 0;
		pid = info->si_pid;
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

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("The PID is: ", 1);
	ft_putstr_color_fd(YELLOW, ft_itoa(getpid()), 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
	}
}
