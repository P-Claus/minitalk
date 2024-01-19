#include "./libft/libft.h"
#include <stdio.h>
#include <signal.h>

int	main(int argc, char *argv[])
{
	char	*pid;
	int		new_pid;

	pid = argv[1];
	if (argc <= 1)
		return (0);
	new_pid = ft_atoi(pid);
	printf("The pid after atoi is: %d\n", new_pid);
	kill(new_pid, SIGINT);

}
