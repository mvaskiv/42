/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:24:13 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/12/27 08:31:18 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_arrclr(char **arr)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (*arr)
	{
		if (arr)
		{
			while (i <= ft_strlen(*arr))
			{
				while (j <= ft_strlen(arr[i]))
					arr[i][j++] = '\0';
				i++;
			}
		}
	}
}
