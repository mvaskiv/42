#include "ft_printf.h"

int 	ft_convert(va_list arg,
					const char * format, char **string, int len)
{
	char 	spec;

	if (*format == 's')
		*string = ft_strjoin(*string, (char*)(va_arg(arg, char *)));
	if (*format == 'd')
		*string = ft_strjoin(*string, ft_itoa(va_arg(arg, int)));
	return (ft_strlen(*string));
}