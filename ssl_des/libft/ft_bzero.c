/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:50:02 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/18 17:55:57 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = '\0';
}
