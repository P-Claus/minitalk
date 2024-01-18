#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*pid;

	pid = argv[1];
	if (argc <= 1)
		return (0);
	printf("The pid is: %s\n", pid);
	printf("The message is: %s\n", argv[2]);



}
