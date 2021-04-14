/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longest_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:26:10 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 14:26:10 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_longest_tab(char **arr)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (arr[j])
	{
		if (ft_strlen(arr[j]) > i)
			i = ft_strlen(arr[j]);
		j++;
	}
	return (i);
}
