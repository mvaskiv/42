/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:54:19 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/18 17:59:24 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	unsigned int			i;
	unsigned char			*tmp_dest;
	unsigned const char		*tmp_src;

	i = 0;
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		if (tmp_src[i] == (unsigned char)c)
			return (&(tmp_dest[i + 1]));
		i++;
	}
	return (NULL);
}
