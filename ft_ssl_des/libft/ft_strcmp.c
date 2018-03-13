/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:01:39 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 14:13:37 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] || s2[i])
		{
			if ((unsigned char)s1[i] > (unsigned char)s2[i])
				return (1);
			if ((unsigned char)s2[i] > (unsigned char)s1[i])
				return (-1);
			i++;
		}
	}
	return (0);
}
