/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:07 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/30 14:04:05 by jdoekiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_check_input(const char *line, char ***env)
{
	if (line[0] == '\0')
		return (1);
	else if (ft_exit(line))
		return (1);
	else if (ft_strchr(line, ';') || ft_strchr(line, '&'))
		return (ft_handle_few(line, *env));
	else if ((line[0] == 'c' && line[1] == 'd' && line[2] == ' ') ||
			(line[0] == 'c' && line[1] == 'd' && !line[2]))
		return (ft_cd(line, env));
	else if (line[0] == 'e' && line[1] == 'n' && line[2] == 'v' && !line[3])
		return (ft_env(*env));
	else if (line[0] == 'e' && line[1] == 'c' && line[2] == 'h' &&
			line[3] == 'o' && line[4] == ' ')
		return (ft_echo(line, env));
	else if (line[0] == 's' && line[1] == 'e' && line[2] == 't' &&
			line[3] == 'e' && line[4] == 'n' && line[5] == 'v' &&
			(line[6] == ' ' || !line[6]))
		return (ft_mod_env(env, line));
	else if (line[0] == 'u' && line[1] == 'n' && line[2] == 's' &&
			line[3] == 'e' && line[4] == 't' && line[5] == 'e' &&
			line[6] == 'n' && line[7] == 'v' && (line[8] == ' ' || !line[8]))
		return (ft_unsetenv(env, line, 0));
	return (0);
}

char	**ft_arrdup(char **arr)
{
	int		i;
	char	**dup;

	i = 0;
	while (arr[i] != NULL)
		i++;
	dup = (char**)malloc(sizeof(char*) * i + 1);
	i = 0;
	while (arr[i] != NULL)
	{
		dup[i] = ft_strdup(arr[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

static void	ft_rid_tab(char **line)
{
	char	*out;
	char 	*in;
	int 	i;
	int 	j;

	j = 0;
	i = 0;
	in = *line;
	out = (char*)malloc(sizeof(char) * ft_strlen(in));
	while (i < ft_strlen(in))
	{
		if (in[i] == '\t')
		{
			out[j++] = ' ';
			i++;
		}
		else
		{
			out[j++] = in[i++];
		}
	}
	out[j] = '\0';
	ft_strdel(line);
	*line = out;
}



int		main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**env;

	line = NULL;
	if (argc <= 0)
		argv = NULL;
	env = ft_arrdup(envp);
	while (42)
	{
		signal(SIGINT, ft_signal_int);
		ft_welcome(&line);
		if (!line)
			break ;
		ft_rid_tab(&line);
		if (line[0] == '.' && line[1] == '/')
			ft_exec_local(&line, &env);
		else if (ft_check_input(line, &env))
			ft_strdel(&line);
		else
			ft_check_exec(&line, &env);
	}
	write(1, "\n", 1);
	return (0);
}
