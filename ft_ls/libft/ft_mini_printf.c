
#include "includes/libft.h"

static int 		ft_process(va_list arg,
				  const char ** restrict format, char **string, t_mini width)
{
	int		len;

	len = 0;
	if (ft_strchr("cCsSpdDioOuUxX", **format))
	{
		len = ft_convert(arg, *format, string, width);
		*format += 1;
		return (len);
	}
	if (ft_strchr("hljz", **format))
		len = ft_set_size(*format, arg, string, width);
	*format += 1;
	return (len);
}

//static int 		ft_prepare_width(va_list arg, const char ** format, int width)
//{
//	if (**format == '*')
//	{
//		width = va_arg(arg, int);
//		*format += 1;
//	}
//	if (**format == '-' && (char**)(format + 1) == '*')
//	{
//		width = (va_arg(arg, int) * (-1));
//		*format += 2;
//	}
//	else
//	{
//		width = ft_atoi(*format);
//		*format += ft_nbrlen((int)width);
//	}
//	return (width);
//}
static void		ft_width_ini(t_mini *width)
{
	width->sign = 0;
	width->type = 0;
	width->width = 0;
}

static int		ft_mini_engine(va_list arg, const char * format, int len)
{
	char 	*string = NULL;
	t_mini	width;
	char 	spec;

	ft_width_ini(&width);
	while ((spec = *format++))
	{
		if (spec == '%')
		{
			if (ft_strchr("*0123456789-+ #", *format))
			{
				if (*format == '-')
				{
					width.sign = 1;
					format += 1;
				}
				if (*format == '0')
				{
					width.type = 1;
					format += 1;
				}
				if (*format == '*')
				{
					width.width = va_arg(arg, int);
					format += 1;
				}
				else
				{
					width.width = ft_atoi(format);
					format += ft_nbrlen(width.width);
				}
			}
			if (ft_strchr("hljzcCsSpdDioOuUxX", *format))
				len += ft_process(arg, &format, &string, width);
		}
		else
			string = ft_addchar(string, spec);
	}
	ft_putstr(string);
	ft_strdel(&string);
	return (len);
}

int 			ft_mini_printf(const char * restrict format, ...)
{
	int 	output;
	va_list arg;

	output = 0;
	va_start(arg, format);
	output = ft_mini_engine(arg, format, output);
	va_end(arg);
	return (output);
}