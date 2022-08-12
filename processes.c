/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:18:09 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/03/13 21:02:12 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*form_cmd(char **paths, char *args)
{
	int		i;
	char	*cmd;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(tmp, args);
		free(tmp);
		if (!access(cmd, X_OK))
			return (cmd);
		free(cmd);
		i++;
	}
	return (0);
}

void	first_process(t_pipex pipex, char **argv, char **envp)
{
	if (dup2(pipex.fd[1], 1) == -1)
		exit(1);
	if (close(pipex.fd[0]) == -1)
		exit(1);
	if (dup2(pipex.infile, 0) == -1)
		exit(1);
	pipex.cmd_args = ft_split(argv[2], ' ');
	if (!pipex.cmd_args)
		exit(1);
	pipex.cmd = form_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child_process(&pipex);
		write(2, "Command not found\n", 18);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_process(t_pipex pipex, char **argv, char **envp)
{
	if (dup2(pipex.fd[0], 0) == -1)
		exit(1);
	if (close(pipex.fd[1]) == -1)
		exit(1);
	if (dup2(pipex.outfile, 1) == -1)
		exit(1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	if (!pipex.cmd_args)
		exit(1);
	pipex.cmd = form_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child_process(&pipex);
		write(2, "Command not found\n", 18);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
