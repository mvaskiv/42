/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:21:48 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 14:22:01 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		**ft_sorttab(char **arr)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[j])
		{
			if (ft_strcmp(arr[j], arr[i]) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
