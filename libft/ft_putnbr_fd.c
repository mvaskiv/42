/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:59:28 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/18 18:03:45 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	int		i[11];
	int		j;

	j = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	while (n)
	{
		i[j++] = n % 10;
		n /= 10;
	}
	i[j] = '\0';
	if (j == 0)
		ft_putchar_fd('0', fd);
	while (--j >= 0)
		ft_putchar_fd(i[j] + '0', fd);
}
