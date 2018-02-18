
#include "ft_printf.h"

#include <stdio.h> // ------------------------->>> to delete

//float 	ft_set_precision(int precision, const char * format)
//{
//	float	after_dot;
//	int 		num_len;
//	long int	fractal_len;
//
//	fractal_len = 1;
//	num_len = ft_nbrlen(precision);
//	while (num_len > 0)
//	{
//		fractal_len *= 10;
//		num_len--;
//	}
//	after_dot = 0.0;
//	after_dot = ((float)precision / (fractal_len));
//	return (after_dot);
//}

int ft_printf_engine(va_list arg, const char * format)
{
	char 	*string = NULL;
	int 	width;
	char 	spec;
	int 	len = 0;

	width = 0;
	while ((spec = *format++))
	{
		if (spec == '%')
		{
			if (ft_strchr("*0123456789-+ #", *format))
			{
				if (*format == '*')
				{
					width = va_arg(arg, int) ;
					format += 1;
				}
				else if (*format == '-' && *++format == '*'){
					width = (va_arg(arg, int) * (-1));
					format += 1;
				}
				else
				{
					width = ft_atoi(--format);
					format += ft_nbrlen((int)width);
				}
			}
//			if (ft_strchr(".", *format++))
// 			{
//				width += ft_set_precision(ft_atoi(format), format);
//				format += ft_nbrlen(width);
//			}
			if (ft_strchr("hljzcCsSpdDioOuUxX", *format))
				len = ft_process(arg, &format, &string, width, len);
		}
//			format = ft_return_to(format, '%');
		else
		{
			if (*format != '%')
				string = ft_addchar(string, *format);
		}
	}
	ft_putstr(string);
	return (len);
}


int 	ft_printf(const char * format, ...)
{
	int 	output;
	va_list arg;

	va_start(arg, format);
	output = ft_printf_engine(arg, format);
	va_end(arg);
	return (output);
}
