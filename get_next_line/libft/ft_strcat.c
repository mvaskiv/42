/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:00:49 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/18 18:04:39 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *dest, const char *src)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (dest[j])
		j++;
	while (src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}
