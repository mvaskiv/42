/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:16:14 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/29 10:16:17 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_check_place(t_tminos *mino, char **map, int s)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	while (x < s)
	{
		y = 0;
		while (y < s)
		{
			if (mino->x[i] < s && mino->y[i] < s
				&& map[mino->x[i]][mino->y[i]] == '.')
				if (++i == 4)
					return (1);
			y++;
		}
		x++;
	}
	return (0);
}
