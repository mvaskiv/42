/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_few.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:46:56 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/22 18:41:05 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	ft_find_delim(const char *line)
{
	int		i;
	char	q;

	i = 0;
	q = '\0';
	while (line[i] != '\0')
	{
		if (line[i] == ';')
		{
			q = ';';
			return (q);
		}
		if (line[i] == '&' && line[i + 1] == '&')
		{
			q = '&';
			return (q);
		}
		i++;
	}
	return (q);
}

int			ft_handle_few(const char *line, char **env)
{
	char	**input;
	char	q;
	int		i;

	i = 0;
	q = ft_find_delim(line);
	input = ft_strsplit(line, q);
	while (input[i] != NULL)
		ft_check_exec(&input[i++], &env);
	ft_arrclr(input);
	return (1);
}
