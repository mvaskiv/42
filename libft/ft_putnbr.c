/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:58:43 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/14 16:40:53 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		putcharr(char c)
{
	write(1, &c, 1);
}

static void		putstrr(char const *s)
{
	int			i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

void			ft_putnbr(int n)
{
	int			i[10];
	int			j;

	j = 0;
	if (n == -2147483648)
	{
		putstrr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		putcharr('-');
		n = -n;
	}
	while (n)
	{
		i[j++] = n % 10;
		n /= 10;
	}
	i[j] = '\0';
	if (j == 0)
		putcharr(48);
	while (--j >= 0)
		putcharr(i[j] + 48);
}
