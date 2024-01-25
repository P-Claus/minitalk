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

void	send_confirmation_to_client(int pid)
{
	kill(pid, SIGUSR1);
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	char_received;
	static int		bit_index;
	(void) context;

	if (sig == SIGUSR1)
		char_received |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		if (char_received == '\0')
		{
			ft_putchar('\n');
			printf("The pid from the sender is: %d\n", info->si_pid);
			send_confirmation_to_client(info->si_pid);
		}
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
	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("The pid is: %d\n", getpid());
	while (1)
		pause();

	return (0);
}
