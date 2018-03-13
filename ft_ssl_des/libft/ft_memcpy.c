/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:53:51 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/18 17:57:25 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*tmp_dest;
	const char		*tmp_src;

	i = 0;
	if (!dest && !src)
		return (NULL);
	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (dest);
}
