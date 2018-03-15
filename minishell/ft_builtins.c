/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:33:33 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 13:06:11 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_cd(char *line, char **name)
{
	char 	*dir;

	dir = NULL;
	if (!line[3])
		chdir(getenv("HOME"));
	else
		chdir(ft_strdup(line + 3));
	*name = ft_strjoin("..", ft_strrchr(getcwd(dir, NULL), '/'));
	ft_strdel(&dir);
}

void	ft_env(char **env)
{
	int 	i;

	i = 0;
	while (env[i] != NULL)
		ft_putendl(env[i++]);
}

void	ft_setenv(char **env, char *line)
{
	int 	i;

	i = ft_strlen(*env);
	env[i + 1] = ft_strdup(line + 7);
}

void	ft_unsetenv(char **env, char *line)
{
	int 	i;

	i = 0;
	while (!(ft_strstr(env[i++], (line + 9))));
}

void	ft_echo(char *line)
{
	int 	i;

	i = 5;
	if (!line[i])
		write(1, "\n", 1);
	else
	{
		while (line[i])
		{
			if (line[i] == '\'' || line[i] == '\"')
				i++;
			else
				ft_putchar(line[i++]);
		}
		write(1, "\n", 1);
	}
}