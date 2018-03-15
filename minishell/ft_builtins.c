/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:33:33 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 18:25:51 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_cd(char *line, char **name)
{
	char 		*dir;
	struct stat	stats;

	dir = NULL;
	if (!line[3])
	{
		chdir(getenv("HOME"));
		*name = ft_strdup("Sweet_Home");
		return (1);
	}
	stat(ft_strjoin(ft_strjoin(getenv("PWD"), "/"), line + 3), &stats);
	if ((chdir(ft_strdup(line + 3))) == 0)
		chdir(ft_strdup(line + 3));
	else if (!(S_ISDIR(stats.st_mode)))
	{
		ft_mini_printf("cd: not a directory: %s\n", line + 3);
		return (1);
	}
//	if ((chdir(ft_strdup(line + 3))) == -1)
	else
	{
		ft_mini_printf("cd: no such file or directory: %s\n", line + 3);
		return (1);
	}
	*name = ft_strjoin("..", ft_strrchr(getcwd(dir, NULL), '/'));
	ft_strdel(&dir);
	return (1);
}

int		ft_env(char **env)
{
	int 	i;

	i = 0;
	while (env[i] != NULL)
		ft_putendl(env[i++]);
	return (1);
}

int		ft_unsetenv(char **env, char *line)
{
	int 	i;

	i = 0;
	while (!(ft_strstr(env[i++], (line + 9))));
	return (1);
}
