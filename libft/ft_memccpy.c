/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:54:19 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/14 15:54:39 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	unsigned int	i;
	char			*tmp_dest;
	const char		*tmp_src;

	i = 0;
	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		if (tmp_src[i] == c)
			return (&(tmp_dest[i + 1]));
		i++;
	}
	return (NULL);
}
