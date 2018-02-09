
#include "ft_printf.h"

#include <stdio.h> // ------------------------->>> to delete


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
			if (ft_strchr("0123456789-+ #", *format))
			{
				width = ft_atoi(format);
				format += ft_nbrlen(width);
			}

            // precision, etc.

            if (ft_strchr("hljz", *format))
                len = ft_set_size(format, arg, &string, width, len);
            if (ft_strchr("cCsSpdDioOuUxX", *format))
                len = ft_convert(arg, format, &string, width);
            format += 1;
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
    long int i = 1221321321321321322;

	printf("%ld mamma mia %c\n", i, 48);
	ft_printf("%ld hello world %c\n", i, 48);
	sleep(5);
}
