#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int	main(void)
{
	int	count;

	count = 1;
	printf("The pid is: %d\n", getpid());
	while (count > 0)
	{
		printf("Count: %d\n", count);
		sleep(1);
		count++;
	}
	return (0);
}
