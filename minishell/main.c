/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:07 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 13:44:04 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_check_input(char *line, char **env, char **name)
{
	if (line[0] == 'e' && line[1] == 'x' && line[2] == 'i' && line[3] == 't')
		exit(0);
	else if (line[0] == 'c' && line[1] == 'd')
	{
		ft_cd(line, name);
		return (1);
	}
	else if (line[0] == 'e' && line[1] == 'n' && line[2] == 'v' && !line[3])
	{
		ft_env(env);
		return (1);
	}
	else if (line[0] == 'e' && line[1] == 'c' && line[2] == 'h' && line[3] == 'o')
	{
		ft_echo(line);
		return (1);
	}
	else if (ft_strstr(line, "setenv"))
	{
		ft_setenv(env, line);
		return (1);
	}
	else if (ft_strstr(line, "unsetenv"))
	{
		ft_unsetenv(env, line);
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

	while(1)
	{
		ft_welcome(&line, name);
		if (ft_check_input(line, envp, &name))
			ft_strdel(&line);
		else
		{
			input = ft_strsplit(line, ' ');
			input[0] = ft_find_path(input);
			if (input[0] == NULL)
				ft_mini_printf("shell: command not found: %s\n", input[1]);
			else
			{
				ft_fork(input, envp);
				ft_strdel(&line);
			}
		}
	}
	return (0);
}
