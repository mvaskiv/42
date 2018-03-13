/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:53:29 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/20 16:12:48 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memalloc(size_t size)
{
	void			*str;
	unsigned int	i;

	i = 0;
	str = malloc(size);
	if (str)
	{
		while (i < size)
			((char *)str)[i++] = 0;
	}
	return (str);
}
