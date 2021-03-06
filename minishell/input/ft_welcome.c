/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_welcome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:31:44 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/22 18:41:05 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	ft_get_quotes(const char *line)
{
	int		i;
	char	q;

	i = 0;
	q = '\0';
	while (line[i] != '\0')
	{
		if (line[i] == '\'')
		{
			q = '\'';
			break ;
		}
		if (line[i] == '\"')
		{
			q = '\"';
			break ;
		}
		i++;
	}
	return (q);
}

int			ft_count_quotes(const char *line)
{
	int		i;
	int		c;
	char	q;

	c = 0;
	i = 0;
	q = ft_get_quotes(line);
	if (q == '\0')
		return (0);
	while (line[i])
	{
		if (line[i] == q)
			c++;
		i++;
	}
	return (c);
}

void		ft_welcome(char **line)
{
	char	*append;
	int		i;
	char	*temp;

	i = 0;
	append = NULL;
	ft_mini_printf("%s%s%s", BYEL, "Sweet_Lemonade", NRM);
	ft_mini_printf("%s_$>%s ", CYN, BWHT);
	get_next_line(0, line);
	if (line == NULL || *line == '\0')
		return ;
	while ((ft_count_quotes(line[0]) % 2) != 0)
	{
		while (i++ <= ft_strlen("Sweet_Lemonade") - 5)
			ft_mini_printf("_");
		i = 0;
		ft_mini_printf("%s ", "dquote>");
		get_next_line(0, &append);
		temp = ft_strjoin(line[0], "\n");
		ft_strdel(&line[0]);
		line[0] = ft_strjoin(temp, append);
		ft_strdel(&temp);
		ft_strdel(&append);
	}
}
