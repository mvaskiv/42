/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:51:40 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/22 19:00:47 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_cd_error(const char *line)
{
	struct stat	stats;
	char		*pwd;
	char		*tmp;

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

static void	ft_substitute_home(char **new_dir)
{
	char	*fullname;
	char	*first;
	char	*second;

	fullname = NULL;
	first = ft_strdup(getenv("HOME"));
	second = ft_strdup(*new_dir + 1);
	fullname = ft_strjoin(first, second);
	ft_strdel(&first);
	ft_strdel(&second);
	if ((chdir(fullname)) == 0)
	{
		ft_strdel(&fullname);
		return ;
	}
	else
	{
		ft_mini_printf("cd: no such file or directory: %s\n", fullname);
		ft_strdel(&fullname);
		return ;
	}
}

static int	ft_check_dir(char **new_dir, char ***env)
{
	char	*old;

	if (!(ft_strncmp(*new_dir, "-", 2)))
	{
		old = ft_get_oldpwd(*env);
		if (old == NULL)
		{
			ft_mini_printf("no OLDPWD set yet\nStatying in the current dir\n");
			return (1);
		}
		chdir(old);
		ft_strdel(&old);
		return (1);
	}
	else if (*new_dir[0] == '~')
	{
		ft_substitute_home(new_dir);
		return (1);
	}
	return (0);
}

static void	ft_set_pwd(char ***env)
{
	char	*new;
	char	*set_new;

	new = getcwd(NULL, 0);
	set_new = ft_strjoin("setenv PWD ", new);
	ft_mod_env(env, set_new);
	ft_strdel(&new);
	ft_strdel(&set_new);
}

int			ft_cd(const char *line, char ***env)
{
	char		*new_dir;
	char		*set_old;
	char		*old;
	char		*home;

	home = ft_get_home(*env);
	old = getcwd(NULL, 0);
	set_old = ft_strjoin("setenv OLDPWD ", old);
	ft_strdel(&old);
	if (line[2] && line[3])
		new_dir = ft_strdup(line + 3);
	if (!line[2] || !line[3])
		chdir(home);
	else if (ft_check_dir(&new_dir, env))
		ft_strdel(&new_dir);
	else if ((chdir(new_dir)) == 0)
		ft_strdel(&new_dir);
	else if (ft_cd_error(line))
		ft_strdel(&new_dir);
	ft_mod_env(env, set_old);
	ft_set_pwd(env);
	ft_strdel(&set_old);
	ft_strdel(&home);
	return (1);
}
