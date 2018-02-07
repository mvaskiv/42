
#include "ft_printf.h"

int 	ft_convert(va_list arg,
					const char * format, char **string, int width)
{
	if (*format == 's')
		*string = ft_strjoin(*string, (char*)(va_arg(arg, char *)));
//	if (*format == 'S')
//		*string =
//	if (*format == 'p')
//		*string =
	if (*format == 'd')
		*string = ft_strjoin(*string, ft_itoa(va_arg(arg, int)));
//	if (*format == 'D')
//		*string =
	if (*format == 'i')
		*string = ft_strjoin(*string, ft_itoa(va_arg(arg, int)));
	if (*format == 'o')
		*string = ft_strjoin(*string, ft_itoa(ft_int_base(va_arg(arg, int), 8)));
//	if (*format == 'O')
//		*string =
	if (*format == 'u')
		*string = ft_strjoin(*string, ft_itoa(va_arg(arg, unsigned int)));
//	if (*format == 'U')
//		*string =
	if (*format == 'x')
		*string = ft_strjoin(*string, ft_dec_to_hex(va_arg(arg, int), 'l'));
	if (*format == 'X')
		*string = ft_strjoin(*string, ft_dec_to_hex(va_arg(arg, int), 'u'));
	if (*format == 'c')
		*string = ft_addchar(*string, va_arg(arg, unsigned char));
	if (width != 0)
		*string = ft_set_width(arg, format, *string, width);
	return (ft_strlen(*string));
}

//void	*ft_set_size(const char *format, va_list arg)
//{
//	void	*data;
//	int 	i;
//
//	i = -1;
//	while (i < )
//
//	return (data);
//}


