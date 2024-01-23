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

	counter = 7;
	char_received = 0;

	struct sigaction sa;
	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("The pid is: %d\n", getpid());
	while (1)
	{
		while (counter >= 0)
		{
			pause();
			char_received = (char_received << counter) | bit_received;
			counter--;
		}
		ft_putchar(char_received);
		break;
	}

	return (0);
}
