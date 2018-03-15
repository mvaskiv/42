/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:07 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 12:34:00 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_check_input(char *line, char **env, char **name)
{
	char 	*dir;

	if (line[0] == 'e' && line[1] == 'x' && line[2] == 'i' && line[3] == 't')
		exit(0);
	else if (line[0] == 'c' && line[1] == 'd')
	{
		if (!line[3])
			chdir(getenv("HOME"));
		else
			chdir(ft_strdup(line + 3));
		*name = ft_strjoin("..", ft_strrchr(getcwd(dir, NULL), '/'));
		ft_strdel(&dir);
		return (1);
	}
	return (0);
}


int		main(int argc, char **argv, char **envp)
{
	char 	**input;
	char 	*line = NULL;
	pid_t 	pid;
	char 	*name = getenv("USER");

	while(!line)
	{
		ft_welcome(&line, name);
		if (ft_check_input(line, envp, &name))
			ft_strdel(&line);
		else
		{
			input = ft_strsplit(line, ' ');
			input[0] = ft_find_path(input[0]);
			ft_fork(input, envp);
			ft_strdel(&line);
		}
	}
	return (0);
}
