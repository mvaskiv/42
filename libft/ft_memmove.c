/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:55:35 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/14 15:55:57 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strneww(unsigned int size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (str[i])
		((char *)str)[i++] = (unsigned char)'\0';
	str[i] = '\0';
	return (str);
}

void		*ft_memmove(void *dest, const void *src, unsigned int n)
{
	char			*tmp;
	char			*tmp_dest;
	const char		*tmp_src;
	unsigned int	i;

	i = 0;
	tmp_dest = dest;
	tmp_src = src;
	tmp = strneww(sizeof(char) * n);
	while (i < n)
	{
		tmp[i] = tmp_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		tmp_dest[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (dest);
}
