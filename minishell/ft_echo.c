/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:25:31 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/16 16:00:26 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_echo_q_pos(char *line, char q)
{
	int 	i;

	i = ft_strlen(line);
	while (line[i] != q)
		i--;
	return (i);
}

static int 	ft_quote_counter(const char *line, int i, char q)
{
	int 	c;
	char 	qq;

	c = 0;
	qq = q == '\'' ? '\"' : '\'';
	while (line[i] != '\0')
	{
		if (line[i] == qq)
			c++;
		i++;
	}
	return (c);
}

static int	ft_echo_quotes(char *line, int i)
{
	char	q;
	char 	*str;
	int 	l;
	int 	j;
	int 	n;

	j = 0;
	q = line[i++];
	n = ft_quote_counter(line, i, q);
	l = ft_echo_q_pos(line, q) - i;
	str = (char*)malloc(sizeof(char)* l + n + 1);
	while (j < l)
	{
		str[j++] = line[i++];
	}
	str[j] = '\0';
	ft_putstr(str);
	ft_strdel(&str);
	return (i - 5);
}

int		ft_echo(char *line)
{
	int i;

	i = 5;
	if (!line[i])
		write(1, "\n", 1);
	else
	{
		while (line[i] != '\0')
		{
			if (line[i] == '\'' || line[i] == '\"')
				i += ft_echo_quotes(line, i);
			if (line[i - 1] && line[i] == ' ' && line[i + 1] != ' ')
				write(1, " ", 1);
			if (line[i] == ' ')
				i++;
			else if (line[i])
				write(1, &line[i++], 1);
		}
		write(1, "\n", 1);
	}
	return (1);
}
