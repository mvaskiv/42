/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:47:34 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/17 15:54:58 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_check_exec(char **line, char ***env)
{
	char 	**input;

	input = ft_strsplit(*line, ' ');
	ft_find_path(input);
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
	char	*envp = ft_strjoin(getenv("PWD"), "/");
	char 	**input;
	char 	*prog;

	prog = ft_strdup(*line + 2);
	input = ft_strsplit(*line, ' ');
	input[0] = ft_strjoin(envp, prog);
	if (input[1] != NULL)
	{
		ft_mini_printf("%s%sshell: can't handle options for local executables yet, sorry\n", NRM, MAG);
		ft_fun_fact();
	}
	else
	{
		ft_fork(input, *env);
		ft_strdel(line);
	}
	ft_arrclr(input);
}