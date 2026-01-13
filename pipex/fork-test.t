#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	pid;

	printf("before fork\n"); // gets called only one time;
	pid = fork();
	printf("pid: %d\n", pid); // gets called twice
	if (pid == 0)
	{
		printf("I am child process\n"); // gets called after parent process;
	}
	else
	{
		// exit(0);  //doesn't kill child process
		printf("I am parent process\n"); // gets called before child process
	}
	return (0);
}
