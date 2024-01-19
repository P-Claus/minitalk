#include "./libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
/*
void	handle_signal(int sig)
{
	printf("You pressed control c\n");
}
*/
int	main(void)
{
	int	count;

	count = 1;
/*
	struct sigaction sa;
	sa.sa_handler = &handle_signal;
	sigaction()
*/
	printf("The pid is: %d\n", getpid());
	while (1)
	{
		printf("Count: %d\n", count);
		sleep(1);
		count++;
	}
	return (0);
}
