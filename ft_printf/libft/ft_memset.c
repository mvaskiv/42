/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:57:09 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/18 18:02:55 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		*ft_memset(void *s, int c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = (unsigned char)c;
	return (s);
}
