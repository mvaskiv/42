/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:07 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/19 16:24:36 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_check_input(const char *line, char ***env)
{
	if (line[0] == '\0')
		return (1);
	else if (ft_exit(line));
	else if (line[0] == 'c' && line[1] == 'd')
		return (ft_cd(line));
	else if (line[0] == 'e' && line[1] == 'n' && line[2] == 'v' && !line[3])
		return (ft_env(*env));
	else if (line[0] == 'e' && line[1] == 'c' && line[2] == 'h' && line[3] == 'o')
		return (ft_echo(line));
	else if (line[0] == 's' && line[1] == 'e' && line[2] == 't' &&
			line[3] == 'e' && line[4] == 'n' && line[5] == 'v' && line[6] == ' ')
	{
		ft_setenv(env, line);
		return (1);
	}
	else if (line[0] == 'u' && line[1] == 'n' && line[2] == 's' &&
			line[3] == 'e' && line[4] == 't' && line[5] == 'e' && line[6] == 'n' &&
			line[7] == 'v' && line [8] == ' ')
	{
		*env = ft_unsetenv(env, line);
		return (1);
	}
	else if (ft_strchr(line, ';') || ft_strchr(line, '&'))
		return (ft_handle_few(line, *env));
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

void	ft_signal_int(int sig)
{
	sig = 0;
	ft_mini_printf("\n%s%s%s", BYEL, "Sweet_Lemonade", NRM);
	ft_mini_printf("%s_$>%s ", CYN, BWHT);
}

int		main(int argc, char **argv, char **envp)
{
	char 	*line = NULL;
	char 	**env;

	if (argc <= 0)
		argv = NULL;
	env = ft_arrdup(envp);
	while (42)
	{
		signal(SIGINT, ft_signal_int);
		ft_welcome(&line);
		if (!line)
			break ;
		if (line[0] == '.' && line[1] == '/')
			ft_exec_local(&line, &env);
		else if (ft_check_input(line, &env))
			ft_strdel(&line);
		else
			ft_check_exec(&line, &env);
	}
	write (1, "\n", 1);
	return (0);
}
