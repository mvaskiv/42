
#include "includes/libft.h"

static char		*ft_set_width(char * str, int width)
{
	char 	*spaces = NULL;
	char 	*string;

	string = (char*)malloc(sizeof(char) * ft_strlen(str));
	ft_memmove(string, str, ft_strlen(str));
	if (ft_strlen(string) > ft_intpositive(width) ||
			ft_strlen(string) == ft_intpositive(width))
		return (string);
	else if (width < 0)
	{
		spaces = ft_string_of_spaces(ft_intpositive(width) - ft_strlen(string));
		string = ft_strjoin(string, spaces);
	}
	else if (width > 0)
	{
		spaces = ft_string_of_spaces((unsigned int)(ft_intpositive(width) - (int)ft_strlen(string)));
		string = ft_strjoin(spaces, string);
	}
	else
		return (string);
	return (string);
}

int 			ft_convert(va_list arg,
				  const char * format, char **string, int width)
{
	if (*format == 's')
		*string = ft_strjoin(*string, (va_arg(arg, char *)));
	if (*format == 'd')
		*string = ft_strjoin(*string, ft_itoa(va_arg(arg, int)));
	if (*format == 'i')
		*string = ft_strjoin(*string, ft_itoa(va_arg(arg, int)));
	if (*format == 'o')
		*string = ft_strjoin(*string, ft_itoa(ft_int_base(va_arg(arg, int), 8)));
	if (*format == 'u')
		*string = ft_strjoin(*string, ft_itoa(va_arg(arg, unsigned int)));
	if (*format == 'x')
		*string = ft_strjoin(*string, ft_dec_to_hex(va_arg(arg, int), 'l'));
	if (*format == 'X')
		*string = ft_strjoin(*string, ft_dec_to_hex(va_arg(arg, int), 'u'));
	if (*format == 'c')
		*string = ft_addchar(*string, va_arg(arg, unsigned char));
	if (width != 0)
		*string = ft_set_width(*string, width);
	return (ft_strlen(*string));
}

static int 		ft_convert_size_set(void *data,
						   const char * format, char **string, int width)
{
	if (*format == 's')
		*string = ft_strjoin(*string, data);
	if (*format == 'd')
		*string = ft_strjoin(*string, ft_itoa(data));
	if (*format == 'i')
		*string = ft_strjoin(*string, ft_itoa(data));
	if (*format == 'o')
		*string = ft_strjoin(*string, ft_itoa(ft_int_base(data, 8)));
	if (*format == 'u')
		*string = ft_strjoin(*string, ft_itoa(data));
	if (*format == 'x')
		*string = ft_strjoin(*string, ft_dec_to_hex(data, 'l'));
	if (*format == 'X')
		*string = ft_strjoin(*string, ft_dec_to_hex(data, 'u'));
	if (*format == 'c')
		*string = ft_addchar(*string, data);
	if (width != 0)
		*string = ft_set_width(*string, width);
	return (ft_strlen(*string));
}

int			ft_set_size(const char *format, va_list arg, char **string, int width)
{
	void	*data = NULL;
	int 	len;

	len = 0;
	if (*format == 'l')
	{
//		if (*++format == 'l')
//			data = (long long int *)va_arg(arg, long long int);
//		else
		data = (long int *)va_arg(arg, long int);
	}
	if (*format == 'h')
	{
//		if (*++format == 'h')
//			data = (long long int *)va_arg(arg, long long int);
//		else
		data = (short int *) va_arg(arg, short int *);
	}
	if (*format == 'j')
		data = (intmax_t *)va_arg(arg, intmax_t);
	if (*format == 'z')
		data = (size_t *)va_arg(arg, size_t);
	if (ft_strchr("cCsSpdDioOuUxX", *++format))
		len = ft_convert_size_set(data, format, string, width);
	return (len);
}
