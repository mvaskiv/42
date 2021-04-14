/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_santas_little_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:23:20 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 14:23:20 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		*ft_set_width(t_mini *width)
{
	char	*spaces;
	char	*string;
	int		i;

	i = ft_strlen(width->string);
	if (i >= width->width)
		return (width->string);
	else if (width->sign == 1)
	{
		spaces = (width->type == 1) ? ft_string_of_zeros(width->width - i) :
			ft_string_of_spaces(width->width - i);
		string = ft_strjoin(width->string, spaces);
	}
	else if (width->sign == 0)
	{
		spaces = (width->type == 1) ? ft_string_of_zeros(width->width - i) :
			ft_string_of_spaces(width->width - i);
		string = ft_strjoin(spaces, width->string);
	}
	else
		return (width->string);
	ft_strdel(&spaces);
	ft_strdel(&width->string);
	return (string);
}

void			ft_convert(va_list arg, t_mini *mini)
{
	if (mini->conv.s)
		mini->string = ft_strdup(va_arg(arg, char*));
	if (mini->conv.d)
		mini->string = ft_itoa(va_arg(arg, int));
	if (mini->conv.i)
		mini->string = ft_itoa(va_arg(arg, int));
	if (mini->conv.o)
		mini->string = ft_itoa(ft_int_base(va_arg(arg, int), 8));
	if (mini->conv.u)
		mini->string = ft_itoa(va_arg(arg, unsigned int));
	if (mini->conv.x)
		mini->string = ft_dec_to_hex(va_arg(arg, int), 'l');
	if (mini->conv.xh)
		mini->string = ft_dec_to_hex(va_arg(arg, int), 'u');
	if (mini->conv.c)
	{
		ft_putchar(va_arg(arg, int));
		return ;
	}
	if (mini->width != 0)
		mini->string = ft_set_width(mini);
	ft_putstr(mini->string);
	ft_strdel(&mini->string);
}
