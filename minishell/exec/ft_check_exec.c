/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:47:34 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/19 16:43:46 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_check_exec(char **line, char ***env)
{
	char 	**input;
	char 	*path;

	input = ft_strsplit(*line, ' ');
	path = ft_get_path(*env);
	ft_find_path(input, path);
	ft_strdel(&path);
	if (input[0] == NULL)
	{
		ft_mini_printf("%s%sshell: command not found: %s%s\n", NRM, RED, input[1], BWHT);
		ft_strdel(&input[1]);
		ft_strdel(line);
	}
	else
	{
		ft_fork(input, *env);
		ft_strdel(line);
	}
	ft_arrclr(input);
}

void	ft_exec_local(char **line, char ***env)
{
	char	*envp;
	char 	**input;
	char 	*prog;
	char 	*env_pwd;

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
		ft_mini_printf("%s%sshell: no such file or directory ./%s\n", NRM, MAG, prog);
		ft_strdel(&prog);
		ft_strdel(line);
		ft_fun_fact();
	}
	else
	{
		ft_strdel(&prog);
		ft_fork(input, *env);
		ft_strdel(line);
	}
	ft_arrclr(input);
}