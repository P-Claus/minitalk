#include "./libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int	bit_received;

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		bit_received = 1;
	else if (sig == SIGUSR2)
		bit_received = 0;
}

int	main(void)
{
	int		counter;
	char	char_received;

	counter = 0;
	char_received = 0;

	struct sigaction sa;
	sa.sa_handler = &handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("The pid is: %d\n", getpid());
	while (1)
	{
		while (counter < 8)
		{
			pause();
//			char_received = (char_received << counter) | bit_received;
			write(1, &bit_received, 1);
			counter++;
		}
		ft_putchar(char_received);
	}

	return (0);
}
