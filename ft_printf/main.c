
#include "ft_printf.h"

#include <stdio.h> // ------------------------->>> to delete


int ft_printf_engine(va_list arg, const char * format)
{
	char 	*string = NULL;
	int 	width;
	char 	spec;
	int 	len = 0;
	void 	*size;

	width = 0;
	while ((spec = *format++))
	{
		if (spec == '%')
		{
			if (ft_isdigit(*format) || (*format == (char)'-') || (*format == (char)'+')
				|| (*format == (char)' ' || (*format == (char)'#')))
			{
				width = ft_atoi(format);
				format += ft_nbrlen(width);
			}
			if (ft_isalpha(*format))
			{
				size = ft_set_size(*format, arg);
				len = ft_convert(arg, format, &string, width);
			}
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


int ft_printf(const char * format, ...)
{
	int 	output;
	va_list arg;

	va_start(arg, format);
	output = ft_printf_engine(arg, format);
	va_end(arg);
	return (output);
}

int 	main(void)
{
	char	*string = "hello";

	printf("%-3x mamma mia %c\n", 42, 48);
	ft_printf("%-3x motherfucker %c\n", 42, 48);
//	sleep(5);
}
