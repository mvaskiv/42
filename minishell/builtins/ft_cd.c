/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:51:40 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/20 17:37:29 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_cd_error(const char *line)
{
	struct stat	stats;
	char		*pwd;
	char 		*tmp;

	tmp = ft_strjoin(getenv("PWD"), "/");
	pwd = ft_strjoin(tmp, line + 3);
	ft_strdel(&tmp);
	if ((stat(pwd, &stats)))
	{
		ft_mini_printf("cd: no such file or directory: %s\n", line + 3);
		ft_strdel(&pwd);
		return (1);
	}
	else if (!(S_ISDIR(stats.st_mode)))
	{
		ft_mini_printf("cd: not a directory: %s\n", line + 3);
		ft_strdel(&pwd);
		return (1);
	}
	return (0);
}

int			ft_cd(const char *line)
{
	char 		*new_dir;

	new_dir = ft_strdup(line + 3);
	if (!line[3])
	{
		chdir(getenv("HOME"));
		ft_strdel(&new_dir);
		return (1);
	}
	if ((chdir(new_dir)) == 0);
	else if (ft_cd_error(line))
	{
		ft_strdel(&new_dir);
		return (1);
	}
	ft_strdel(&new_dir);
	return (1);
}
