/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:26:30 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 14:26:30 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_int_base(int number, int base)
{
	unsigned int	output;
	int				position;

	output = 0;
	position = 1;
	if (base == 8)
	{
		while (number)
		{
			output += (number % base) * position;
			number /= base;
			position *= 10;
		}
	}
	if (base == 16)
	{
		while (number)
		{
			output += (number % base) * position;
			number /= base;
			position *= 10;
		}
	}
	return (output);
}
