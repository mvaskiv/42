/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:25:31 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 16:27:07 by mvaskiv          ###   ########.fr       */
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


static int	ft_echo_quotes(char *line, int i)
{
	char	q;
	char 	*str;
	int 	n;
	int 	l;
	int 	j;

	j = 0;
	q = line[i++];
	l = ft_echo_q_pos(line, q) - i;
	str = (char*)malloc(sizeof(char)* l + 1);
	while (j < l)
	{
		str[j++] = line[i++];
	}
	str[j] = '\0';
	ft_putstr(str);
	ft_strdel(&str);
	return (i);
}

void		ft_echo(char *line)
{
	int i;

	i = 5;
	if (!line[i])
		write(1, "\n", 1);
	else
	{
		while (line[i])
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
}
