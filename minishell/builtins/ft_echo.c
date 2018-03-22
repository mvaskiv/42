/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:25:31 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/22 14:44:25 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_echo_q_pos(const char *line, char q, int i)
{
	while (line[i] != q)
		i++;
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

char 	*ft_get_env(char *name, char **env)
{
	int		i;
	char 	*value;

	i = 0;
	while (env[i] != NULL)
	{
		if (env[i][0] == name[0] && ft_strstr(env[i], name))
		{
			value = ft_strdup(env[i] + ft_strlen(name));
			return (value);
		}
		i++;
	}
	return (NULL);
}

char 	*ft_get_envname_echo(int i, int j, int l, const char *line)
{
	char 	*name;
	char 	*fullname;

	name = (char*)malloc(sizeof(char) * (j - i) + 1);
	while (l < (j - i - 1))
	{
		name[l] = line[i + l];
		l++;
	}
	name[l++] = '\0';
	fullname = ft_strjoin(name, "=");
	ft_strdel(&name);
	return (fullname);
}

int 	ft_echo_env(const char *line, int i, char ***env)
{
	int 	j;
	char 	*value;
	char 	*fullname;
	int 	l;

	l = 0;
	j = ++i;
	while (ft_isalpha(line[j++]));
	fullname = ft_get_envname_echo(i, j, l, line);
	l = ft_strlen(fullname);
	if (!(value = ft_get_env(fullname, *env)))
	{
		ft_strdel(&fullname);
		return (l);
	}
	else
		ft_putstr(value);
	ft_strdel(&value);
	ft_strdel(&fullname);
	return (l);
}

static int	ft_echo_quotes(const char *line, int i, char ***env)
{
	char	q;
	int 	l;
	int 	j;
	int 	n;

	n = 0;
	j = 0;
	q = line[i++];
	l = ft_echo_q_pos(line, q, i) - 6;
	while (j < l)
	{
		if (line[i] && line[i] != '$')
		{
			ft_putchar(line[i++]);
			j++;
		}
		else if (line[i] == '$')
		{
			n = ft_echo_env(line, i, env);
			i += n;
			j += n;
		}
	}
	return (++i);
}

int		ft_echo(const char *input, char ***env)
{
	int i;
	char 	*line;

	i = 5;
	if (!input[i])
		write(1, "\n", 1);
	else
	{
		line = ft_strdup(input);
		while (line[i] != '\0')
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
			else if (line[i] && line[i] != '\''&& line[i] != '\"' && line[i] != ' ')
				write(1, &line[i++], 1);
		}
		write(1, "\n", 1);
		ft_strdel(&line);
	}
	return (1);
}
//
//int		ft_echo_check(const char *input)
//{
//
//}