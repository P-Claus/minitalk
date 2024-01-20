#include "./libft/libft.h"
#include <stdio.h>
#include <signal.h>
/*
void	send_signal(int pid, )
{

}
*/
void	convert_char_to_bits(char c)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		if (((c >> count) & 1) == 1)
			ft_putchar('1');//send kill SIGUSR1
		if (((c >> count) & 1) == 0)
			ft_putchar('0'); //send kill SIGUSR2
		count--;
	}

}


int	main(int argc, char *argv[])
{
	char	*pid;
	char	*string;
	int		new_pid;
	int		index;

	index = 0;
	if (argc <= 1)
		return (0);
	pid = argv[1];
	string = argv[2];
	new_pid = ft_atoi(pid);
	printf("The pid after atoi is: %d\n", new_pid);
	while (string[index] != '\0')
		convert_char_to_bits(string[index++]);


	//kill(new_pid, SIGINT);

	return (0);
}
