/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:10:56 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 15:01:59 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_process(va_list arg,
	const char **format, t_mini *mini)
{
	int		len;

	len = 0;
	mini->conv.c = (**format == 'c') ? 1 : 0;
	mini->conv.s = (**format == 's') ? 1 : 0;
	mini->conv.d = (**format == 'd') ? 1 : 0;
	mini->conv.i = (**format == 'i') ? 1 : 0;
	mini->conv.o = (**format == 'o') ? 1 : 0;
	mini->conv.u = (**format == 'u') ? 1 : 0;
	mini->conv.x = (**format == 'x') ? 1 : 0;
	mini->conv.xh = (**format == 'X') ? 1 : 0;
	ft_convert(arg, mini);
	return (1);
}

static void		ft_width_ini(t_mini *mini)
{
	mini->string = NULL;
	mini->sign = 0;
	mini->type = 0;
	mini->width = 0;
	mini->conv.c = 0;
	mini->conv.s = 0;
	mini->conv.d = 0;
	mini->conv.i = 0;
	mini->conv.o = 0;
	mini->conv.u = 0;
	mini->conv.x = 0;
	mini->conv.xh = 0;
}

static int		ft_scan_width(t_mini *mini, const char *format,
	va_list arg, int i)
{
	if (*format == '-')
	{
		mini->sign = 1;
		format += 1;
		i += 1;
	}
	if ((*format) == '0')
	{
		mini->type = 1;
		format += 1;
		i++;
	}
	if ((*format) == '*')
	{
		mini->width = va_arg(arg, int);
		i++;
	}
	else
	{
		mini->width = ft_atoi(format);
		i += ft_nbrlen(mini->width);
	}
	return (i);
}

static int		ft_mini_engine(va_list arg, const char *format)
{
	t_mini	mini;
	char	spec;
	int		output;

	output = 0;
	ft_width_ini(&mini);
	while ((spec = *format++))
	{
		if (spec == '%')
		{
			if (ft_strchr("*0123456789-+ #", *format))
				format += ft_scan_width(&mini, format, arg, 0);
			if (ft_strchr("cCsSpdDioOuUxX", *format))
				format += ft_process(arg, &format, &mini);
		}
		else
			ft_putchar(spec);
	}
	return (output);
}

int				ft_mini_printf(const char *format, ...)
{
	int		output;
	va_list	arg;

	output = 0;
	va_start(arg, format);
	output = ft_mini_engine(arg, format);
	va_end(arg);
	return (output);
}
