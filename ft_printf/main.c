
#include "ft_printf.h"

#include <stdio.h> // ------------------------->>> to delete


int ft_printf_engine(va_list arg, const char *format)
{
	return 0;
}


int ft_printf(const char *format, ...)
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
	printf("%5d", 12);
}