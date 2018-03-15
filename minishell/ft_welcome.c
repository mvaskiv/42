/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_welcome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:31:44 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 15:09:05 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int 	ft_count_quotes(char *line)
{
	int		i;
	int 	c;
	char 	q;

	c = 0;
	i = 0;
	q = NULL;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			q = '\'';
			break;
		}
		if (line[i] == '\"')
		{
			q = '\"';
			break;
		}
		i++;
	}
	while (line[i])
	{
		if (line[i] == q)
			c++;
		i++;
	}
	return (c);
}

void	ft_welcome(char **line, char *name)
{
	char	*append;
	int 	i;

	i = 0;
	append = NULL;
	ft_mini_printf("%s%s%s", YEL, name, NRM);
	ft_mini_printf("%s_$>%s ", CYN, CYN);
	get_next_line(0, line);
	while ((ft_count_quotes(line[0]) % 2) != 0)
	{
		while (i++ <= ft_strlen(name) - 5)
			ft_mini_printf("_");
		i = 0;
		ft_mini_printf("%s ", "dquote>");
		get_next_line(0, &append);
		line[0] = ft_strjoin(line[0], "\n");
		line[0] = ft_strjoin(line[0], append);
		ft_strdel(&append);
	}
}