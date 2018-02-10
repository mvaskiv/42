
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

int 	ft_convert_size_set(void *data,
                  const char * format, char **string, int width)
{
//	if (*format == 's')
//		*string = ft_strjoin(*string, (char*)(va_arg(arg, char *)));
////	if (*format == 'S')
////		*string =
////	if (*format == 'p')
////		*string =
    if (*format == 'd')
        *string = ft_strjoin(*string, ft_itoa(data));
////	if (*format == 'D')
////		*string =
//	if (*format == 'i')
//		*string = ft_strjoin(*string, ft_itoa(va_arg(arg, int)));
//	if (*format == 'o')
//		*string = ft_strjoin(*string, ft_itoa(ft_int_base(va_arg(arg, int), 8)));
////	if (*format == 'O')
////		*string =
//	if (*format == 'u')
//		*string = ft_strjoin(*string, ft_itoa(va_arg(arg, unsigned int)));
////	if (*format == 'U')
////		*string =
//	if (*format == 'x')
//		*string = ft_strjoin(*string, ft_dec_to_hex(va_arg(arg, int), 'l'));
//	if (*format == 'X')
//		*string = ft_strjoin(*string, ft_dec_to_hex(va_arg(arg, int), 'u'));
//	if (*format == 'c')
//		*string = ft_addchar(*string, va_arg(arg, unsigned char));
//	if (width != 0)
//		*string = ft_set_width(arg, format, *string, width);
    return (ft_strlen(*string));
}

int	ft_set_size(const char *format, va_list arg, char **string, int width, int len)
{
	void	*data = NULL;

	if (*format == 'l')
	{
//		if (*++format == 'l')
//			data = (long long int *)va_arg(arg, long long int);
//		else
			data = (long int *)va_arg(arg, long int);
	}
	if (*format == 'h')
        data = (short int *)va_arg(arg, short int);
    if (*format == 'j')
		data = (intmax_t *)va_arg(arg, intmax_t);
	if (*format == 'z')
		data = (size_t *)va_arg(arg, size_t);
    if (ft_strchr("cCsSpdDioOuUxX", *++format))
        len += ft_convert_size_set(data, format, string, width);
	return (len);
}


