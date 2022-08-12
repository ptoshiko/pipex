/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:50:02 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/03/15 22:43:04 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		infile;
	int		outfile;
	char	*env_paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;
void	first_process(t_pipex pipex, char **argv, char **envp);
void	second_process(t_pipex pipex, char **argv, char **envp);
void	free_parent_process(t_pipex *pipex);
void	free_child_process(t_pipex *pipex);
#endif 

#define CMD 0;

typedef struct s_token
{
	char *value;
	int type;
}	t_token;

