/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:25:31 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/22 15:30:46 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_do_echo(const char *line, char ***env, int i)
{
	if (line[i] == '\'' || line[i] == '\"')
		i = ft_echo_quotes(line, i, env);
	if (line[i] == '$')
		i += ft_echo_env(line, i, env);
	if (line[i] == ' ')
	{
		if (line[i + 1] && line[i + 1] != ' ')
			write(1, " ", 1);
		i++;
	}
	else if (line[i] && line[i] != '\'' && line[i] != '\"' && line[i] != ' ')
		write(1, &line[i++], 1);
	return (i);
}

int		ft_echo(const char *input, char ***env)
{
	int		i;
	char	*line;

	i = 5;
	if (!input[i])
		write(1, "\n", 1);
	else
	{
		line = ft_strdup(input);
		while (line[i] != '\0')
		{
			i = ft_do_echo(line, env, i);
		}
		write(1, "\n", 1);
		ft_strdel(&line);
	}
	return (1);
}
