/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:13:37 by tlaukat           #+#    #+#             */
/*   Updated: 2024/04/10 19:36:30 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// 0 = stdin, 1 = stdout, 2 = stderr

void	free_pointers(char *pointer, char **p_array)
{
	int	i;

	if (pointer != NULL)
	{
		free(pointer);
	}
	if (p_array != NULL)
	{
		i = 0;
		while (p_array[i] != NULL)
		{
			free(p_array[i]);
			i++;
		}
		free(p_array);
	}
}

void	execute_cmd(char *cmds, char **envp)
{
	char	**list_command;
	char	*path;

	list_command = ft_split(cmds, ' ');
	path = ft_strjoin("/bin/", list_command[0]);
	if (execve(path, list_command, envp) == -1)
	{
		ft_printf("exceve: command not found: %s\n", list_command[0]);
		free_pointers(path, list_command);
		exit(0);
	}
	free_pointers(path, list_command);
}

void	parent(char **argv, int p_fd[2], char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		exit(0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	execute_cmd(argv[2], envp);
}

void	child(char **argv, int p_fd[2], char **envp)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	execute_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	p_fd[2];

	if (argc != 5)
		return (ft_printf("Wrong number of arguments\n"), 1);
	if (pipe(p_fd) == -1)
		return (perror("pipe"), -1);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), -1);
	if (pid == 0)
		child(argv, p_fd, envp);
	else
		parent(argv, p_fd, envp);
}
