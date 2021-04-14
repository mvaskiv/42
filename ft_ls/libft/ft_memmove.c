/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:55:35 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/18 18:09:27 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char				*tmp_dest;
	char				*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	if (tmp_dest < tmp_src)
	{
		while (n-- > 0)
			*tmp_dest++ = *tmp_src++;
	}
	else
	{
		tmp_src += n;
		tmp_dest += n;
		while (n-- > 0)
			*--tmp_dest = *--tmp_src;
	}
	return (dest);
}
