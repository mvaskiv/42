/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:07 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/16 12:39:09 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_check_input(char *line, char ***env, char **name)
{
	if (line[0] == '\0')
		return (1);
	else if (line[0] == 'e' && line[1] == 'x' && line[2] == 'i' && line[3] == 't')
		exit(0);
	else if (line[0] == 'c' && line[1] == 'd')
		return (ft_cd(line, name));
	else if (line[0] == 'e' && line[1] == 'n' && line[2] == 'v' && !line[3])
		return (ft_env(*env));
	else if (line[0] == 'e' && line[1] == 'c' && line[2] == 'h' && line[3] == 'o')
		return (ft_echo(line));
	else if (ft_strstr(line, "setenv "))
	{
		*env = ft_setenv(env, line);
		return (1);
	}
	else if (ft_strstr(line, "unsetenv "))
	{
		*env = ft_unsetenv(env, line);
		return (1);
	}
	return (0);
}

char 	**ft_arrdup(char **arr)
{
	int		i;
	char	**dup;

	i = 0;
	while (arr[i++] != NULL);
	dup = (char**)malloc(sizeof(char*) * i);
	i = 0;
	while (arr[i] != NULL)
	{
		dup[i] = ft_strdup(arr[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

int		main(int argc, char **argv, char **envp)
{
	char 	**input;
	char 	*line = NULL;
	pid_t 	pid;
	char 	*name = getenv("USER");
	char 	**env;

	env = ft_arrdup(envp);
	signal(SIGINT, SIG_IGN);
	while(1)
	{
		ft_welcome(&line, name);
		if (ft_check_input(line, &env, &name))
			ft_strdel(&line);
		else
		{
			input = ft_strsplit(line, ' ');
			ft_find_path(input);
			if (input[0] == NULL)
				ft_mini_printf("shell: command not found: %s\n", input[1]);
			else
			{
				ft_fork(input, env);
				ft_strdel(&line);
			}
			ft_arrclr(input);
		}
	}
	return (0);
}
