/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:56:55 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/29 12:44:56 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_connections(char *s)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i] && i < 21)
	{
		if (s[i] == '#' && s[i + 1] == '#' && (i + 1) < 21)
			k++;
		if (s[i] == '#' && s[i - 1] == '#' && (i - 1) >= 0)
			k++;
		if (s[i] == '#' && s[i + 5] == '#' && (i + 5) < 21)
			k++;
		if (s[i] == '#' && s[i - 5] == '#' && (i - 5) >= 0)
			k++;
		i++;
	}
	if (k == 8 || k == 6)
		return (1);
	return (0);
}

int		ft_val_for_one(char *s)
{
	size_t	i;
	size_t	h;
	size_t	p;

	i = 0;
	h = 0;
	p = 0;
	while (((s[i] == '.' || s[i] == '#')
		|| (s[i % 5] == '\n' && (i % 5) == 4)) && i < 20)
	{
		if (h == 5)
			return (0);
		if (s[i] == '#')
			h++;
		if (s[i] == '.')
			p++;
		i++;
	}
	return (((h == 4 && p == 12) && ((s[i] == '\n' && s[i + 1] != '\0')
		|| s[i] == '\0') && ft_connections(s) == 1) ? 1 : 0);
}

int		ft_val_for_each(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (ft_val_for_one(s + i))
			i += 21;
		else
			return (0);
	}
	return (1);
}
