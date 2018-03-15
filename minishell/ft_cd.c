/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:51:40 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 18:52:22 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_cd_error(char *line)
{
	struct stat	stats;

	if ((stat(ft_strjoin(ft_strjoin(getenv("PWD"), "/"), line + 3), &stats)))
	{
		ft_mini_printf("cd: no such file or directory: %s\n", line + 3);
		return (1);
	}
	else if (!(S_ISDIR(stats.st_mode)))
	{
		ft_mini_printf("cd: not a directory: %s\n", line + 3);
		return (1);
	}
	return (0);
}

int			ft_cd(char *line, char **name)
{
	char		*dir;

	dir = NULL;
	if (!line[3])
	{
		chdir(getenv("HOME"));
		*name = ft_strdup("Sweet_Home");
		return (1);
	}
	else if (ft_cd_error(line))
		return (1);
	else if ((chdir(ft_strdup(line + 3))) == 0)
		chdir(ft_strdup(line + 3));
	*name = ft_strjoin("..", ft_strrchr(getcwd(dir, NULL), '/'));
	ft_strdel(&dir);
	return (1);
}
