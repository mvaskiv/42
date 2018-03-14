/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:07 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/14 19:02:55 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_fork(char **input, char **env)
{
	int 	status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_putendl("error");
	else if (pid == 0)
	{
		execve(input[0], &input[0], env);
		wait(&status);
	}
	else
	{
//		return ;
		waitpid(pid, &status, 0);
	}
//	exit(0);
}

void	ft_welcome(char **line)
{
	ft_mini_printf("%s%s%s", YEL, getenv("USER"), NRM);
	ft_mini_printf("%s_$>%s ", CYN, NRM);
	get_next_line(0, line);
}

void	ft_cd(char ***env, char *line)
{
	int 	i;
	char 	**envp = *env;

	i = 0;
	while (!(ft_strstr(envp[i++], "PWD")));
	envp[i - 1] = ft_strjoin(ft_strjoin(envp[i - 1], "/"), ft_strdup(line + 3));
}

int		ft_check_input(char *line, char **env)
{
	if (line[0] == 'e' && line[1] == 'x' && line[2] == 'i' && line[3] == 't')
		exit(0);
	else if (line[0] == 'c' && line[1] == 'd')
	{
		chdir(ft_strdup(line + 3));
		return (1);
	}
	return (0);
}


int		main(int argc, char **argv, char **envp)
{
	char 	**input;
	char 	*line = NULL;
	pid_t 	pid;


	while(42)
	{
		ft_welcome(&line);
		if (ft_check_input(line, envp))
			NULL;
		else
		{
			input = ft_strsplit(line, ' ');
			//	pid = fork();
			input[0] = ft_find_path(input[0]);
			ft_fork(input, envp);
			ft_strdel(&line);
		}
//		if (line == "exit")
//			return (0);
	}
	return (0);
}
