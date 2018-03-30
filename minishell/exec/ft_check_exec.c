/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:47:34 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/30 13:59:11 by jdoekiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_path_set(char **input, char *path)
{
	struct stat	stats;
	int 		i;

	if (ft_strncmp(input[0], "/", 1))
		i = ft_find_path(input, path);
	else
	{
		stat(input[0], &stats);
		if ((access(input[0], F_OK) == 0) && (!(S_ISDIR(stats.st_mode))))
			return (1);
		else
		{
			ft_mini_printf("shell: permission denied\n");
			return (0);
		}
	}
	return (i);
}

static int	ft_check_null(char **input, char **line, char **path)
{
    if (input[0] == NULL)
	{
		ft_strdel(line);
		ft_strdel(path);
		ft_arrclr(input);
        return (1);
	}
    return (0);
}

void		ft_check_exec(char **line, char ***env)
{
	char	**input;
	char	*path;

	if (!(path = ft_get_path(*env)))
	{
		ft_mini_printf("environmental variable PATH is not set\n");
		ft_strdel(line);
		return ;
	}
	input = ft_strsplit(*line, ' ');
    if (ft_check_null(input, line, &path))
        return ;
	if (ft_path_set(input, path) == 1)
		ft_fork(input, *env);
	else
		ft_mini_printf("%s", BWHT);
	ft_strdel(&path);
	ft_strdel(line);
	ft_arrclr(input);
}

void		ft_exec_local(char **line, char ***env)
{
	char	*envp;
	char	**input;
	char	*prog;
	char	*env_pwd;

	env_pwd = ft_get_pwd(*env);
	envp = ft_strjoin(env_pwd, "/");
	input = ft_strsplit(*line, ' ');
	prog = ft_strdup(input[0] + 2);
	ft_strdel(&input[0]);
	input[0] = ft_strjoin(envp, prog);
	ft_strdel(&env_pwd);
	ft_strdel(&envp);
	if (access(input[0], X_OK) != 0)
	{
		ft_mini_printf("%s%sshell: no such file or directory ", NRM, MAG);
		ft_mini_printf("./%s\n", prog);
		ft_fun_fact();
	}
	else
		ft_fork(input, *env);
	ft_strdel(&prog);
	ft_strdel(line);
	ft_arrclr(input);
}
