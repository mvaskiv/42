/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:24:13 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 19:40:11 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_arrclr(char **arr)
{
	int		i;

	i = 0;
	if (*arr != NULL)
	{
		while (arr[i] != NULL)
			ft_strdel(&arr[i++]);
	}
	free(arr);
}
