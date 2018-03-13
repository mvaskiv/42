/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:07:38 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/18 18:08:29 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int							ft_strncmp(const char *s1,
	const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == i)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		if ((unsigned char)s2[i] > (unsigned char)s1[i])
			return (-1);
		i++;
	}
	return (0);
}
