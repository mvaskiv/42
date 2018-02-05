
#include "ft_printf.h"

#include <stdio.h> // ------------------------->>> to delete


int ft_printf_engine(va_list arg, const char * format)
{
	char 	*string = NULL;
	char 	spec;
	int 	len = 0;

	while ((spec = *format++))
	{
		if (spec == '%')
		{
			if (ft_isalpha(*format))
				len = ft_convert(arg, format, &string, len);
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

	//printf("%s\n", string);
	ft_printf("%s %d", string, 48);
	sleep(5);
}