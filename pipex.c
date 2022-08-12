/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:04:16 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/03/15 21:43:21 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipe(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH", envp[i], 4))
		i++;
	if (envp[i] == NULL)
	{
		write(2, "Invalid envp\n", 13);
		exit(1);
	}
	return (envp[i] + 5);
}

int	ft_continue(t_pipex pipex, char **argv, char **envp)
{
	pipex.env_paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.env_paths, ':');
	if (!pipex.cmd_paths)
		return (1);
	pipex.pid1 = fork();
	if (!pipex.pid1)
		first_process(pipex, argv, envp);
	pipex.pid2 = fork();
	if (!pipex.pid2)
		second_process(pipex, argv, envp);
	close_pipe(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_parent_process(&pipex);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		write(1, "Invalid number of arguments.\n", 29);
		return (1);
	}
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
	{
		perror("open infile error");
		return (1);
	}
	pipex.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.infile < 0)
	{
		perror("open outfile error");
		return (1);
	}
	if (pipe(pipex.fd) < 0)
	{
		perror("pipe error");
		return (1);
	}
	return (ft_continue(pipex, argv, envp));
}
