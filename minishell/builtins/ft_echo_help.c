/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:55:25 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/22 16:21:23 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_echo_q_pos(const char *line, char q, int i)
{
	while (line[i] != q)
		i++;
	return (i - 1);
}

static char	*ft_get_env(char *name, char **env)
{
	int		i;
	char	*value;

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

static char	*ft_get_envname_echo(int i, int j, int l, const char *line)
{
	char	*name;
	char	*fullname;

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

int			ft_echo_env(const char *line, int i, char ***env)
{
	int		j;
	char	*value;
	char	*fullname;
	int		l;

	l = 0;
	j = ++i;
	while (ft_isalpha(line[j]))
		j++;
	j++;
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

int			ft_echo_quotes(const char *line, int i, char ***env)
{
	char	q;
	int		l;
	int		n;

	n = 0;
	q = line[i++];
	l = ft_echo_q_pos(line, q, i);
	while (i <= l && line[i + 1])
	{
		if (line[i] && line[i] != '$')
			ft_putchar(line[i++]);
		else if (line[i] == '$')
		{
			n = ft_echo_env(line, i, env);
			i += n;
		}
	}
	i += 1;
	return (i);
}
