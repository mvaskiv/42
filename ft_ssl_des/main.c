/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:54:23 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/13 19:14:29 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

long long	ft_dec_to_bin(int dec)
{
	long long	binary = 0;
	int			i = 0;
	int 		r = 0;
	i = 1;
	while (dec != 0)
	{
		r = dec % 2;
		dec /= 2;
		binary += r * i;
		i *= 10;
	}
	return (binary);
}

int 		ft_bin_to_dec(long long bin)
{
	int			dec = 0;
	int			i = 0;
	long long	r = 0;
	i = 1;
	while (bin != 0)
	{
		r = bin % 10;
		bin /= 10;
		dec += (r * i);
		i *= 2;
	}
	return (dec);
}

int main(int argc, char **argv)
{
	char		table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
							'I', 'J', 'K', 'L', 'M','N', 'O', 'P',
							'Q', 'R', 'S', 'T', 'U','V', 'W', 'X',
							'Y', 'Z', 'a', 'b', 'c','d', 'e', 'f',
							'g', 'h', 'i', 'j', 'k','l', 'm', 'n',
							'o', 'p', 'q', 'r', 's','t', 'u', 'v',
							'w', 'x', 'y', 'z', '0','1', '2', '3',
							'4', '5', '6', '7', '8','9', '+', '/'};
	int			bin_row[23];
	int			i = 1;
	char 		a = 'M';
	int 		r = 1;
	long long	n = 0;
	long long	b = 10011;
	int 		d = 0;
	long long 	t = 1;

	i = 0;
	char 		*man = "Man";

//	while (i <= 23)
//	{
//		n = ft_dec_to_bin(*man++);
//		while (n >= 10)
//		{
//			bin_row[i] = n % 10;
//			n /= 10;
//			i++;
//		}
	i = 0;
	r = 0;
	int co = 0;
	while (r < 6)
	{
		bin_row[r] = ((*man >> i++) & 0x01);
		co++;
		r++;
	}
	i = 0;
	co = 0;
	*man++;
	while (r < 14)
	{
		bin_row[r] = ((*man >> i++) & 0x01);
		co++;
		r++;
	}
	i = 0;
	r = 14;
	co = 0;
	*man++;
	while (r < 23)
	{
		bin_row[r] = ((*man >> i++) & 0x01);
		co++;
		r++;
	}

	int			dec = 0;
	i = 1;
	r = 0;
	int 		q = 2;
	while (q <= 6)
	{
		r = bin_row[q] % 10;
		q++;
		dec += (r * i);
		i *= 2;
	}

//	b = ft_dec_to_bin('M');
//	b /= 100;
//	d = ft_bin_to_dec(b);

	ft_mini_printf("%c", table[dec]);
//	while (i < 7)
//		ft_mini_printf("%d", (a >> 0) & 0x01);
	return 0;
}
