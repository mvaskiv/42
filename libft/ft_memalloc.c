/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:53:29 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/14 15:53:43 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(unsigned int size)
{
	void			*str;
	unsigned int	i;

	i = 0;
	str = malloc(size);
	if (str)
	{
		while (i < size)
			((char *)str)[i++] = (unsigned char)'\0';
	}
	return (str);
}
