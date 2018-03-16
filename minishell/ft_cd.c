/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:51:40 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/16 16:45:30 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_cd_error(const char *line)
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

int			ft_cd(const char *line, char **name)
{
	char		*dir;
	char 		*new_dir;

	new_dir = ft_strdup(line + 3);
	dir = NULL;
	if (!line[3])
	{
		chdir(getenv("HOME"));
		ft_strclr(*name);
		*name = ft_strdup("Sweet_Home");
		return (1);
	}
	if ((chdir(new_dir)) == 0);
	else if (ft_cd_error(line))
		return (1);
	dir = getcwd(dir, NULL);
	ft_strclr(*name);
	*name = ft_strjoin("..", ft_strrchr(dir, '/'));
	ft_strdel(&new_dir);
	ft_strdel(&dir);
	return (1);
}
