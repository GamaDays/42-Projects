#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**cmds;

	printf("argc: \n");
	printf("%d\n", argc);
	i = 0;
	printf("argv: \n");
	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	i = 0;
	printf("envp: \n");
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	printf("execve test:\n");
	cmds = (char **)malloc(3 * sizeof(char *));
	cmds[0] = "I get ignored :(";
	cmds[1] = "infile.txt";
	cmds[2] = "-l";
	cmds[3] = NULL;
	if (execve("/usr/bin/ls", cmds, envp) == -1)
		;
	return (perror("execve"), 0);
	return (0);
}
