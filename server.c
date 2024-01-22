#include "./libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

void	handle_signal(int sig)
{
	static int		bit_received;
	static char	character_received;

	printf("it works%d\n", sig);
}

int	main(void)
{

	struct sigaction sa;
	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("The pid is: %d\n", getpid());

	while (1)
	{
		
		pause();
	}

	return (0);
}
