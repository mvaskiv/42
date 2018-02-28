
#include "includes/libft.h"

static char		*ft_set_width(char * str, t_mini width)
{
	char 	*spaces = NULL;
	char 	*string = NULL;

	string = ft_strdup(str);
//	if (str)
//		ft_strdel(&str);
	if (ft_strlen(string) >= width.width)
		return (string);
	else if (width.sign == 1)
	{
		spaces = (width.type == 1) ? ft_string_of_zeros(width.width - ft_strlen(string)) : ft_string_of_spaces(width.width - ft_strlen(string));
		string = ft_strjoin(string, spaces);
	}
	else if (width.sign == 0)
	{
		spaces = (width.type == 1) ? ft_string_of_zeros(width.width - ft_strlen(string)) : ft_string_of_spaces(width.width - ft_strlen(string));
		string = ft_strjoin(spaces, string);
	}
	else
		return (string);
//	ft_strdel(&spaces);
	return (string);
}

int 			ft_convert(va_list arg,
				  const char * format, char **string_o, t_mini width)
{
	char 	*string = NULL;

	if (*format == 's')
		string = ft_strjoin(string, va_arg(arg, char*));
	if (*format == 'd')
		string = ft_strjoin(string, ft_itoa(va_arg(arg, int)));
	if (*format == 'i')
		string = ft_strjoin(string, ft_itoa(va_arg(arg, int)));
	if (*format == 'o')
		string = ft_strjoin(string, ft_itoa(ft_int_base(va_arg(arg, int), 8)));
	if (*format == 'u')
		string = ft_strjoin(string, ft_itoa(va_arg(arg, unsigned int)));
	if (*format == 'x')
		string = ft_strjoin(string, ft_dec_to_hex(va_arg(arg, int), 'l'));
	if (*format == 'X')
		string = ft_strjoin(string, ft_dec_to_hex(va_arg(arg, int), 'u'));
	if (*format == 'c')
		string = ft_addchar(string, va_arg(arg, unsigned char));
	if (width.width != 0)
		string = ft_set_width(string, width);
	*string_o = ft_strjoin(*string_o, string);
	ft_strdel(&string);
	return (ft_strlen(*string_o));
}

static int 		ft_convert_size_set(void *data,
						   const char * format, char **string, t_mini width)
{
	if (*format == 's')
		*string = ft_strjoin(*string, (char*)data);
	if (*format == 'd')
		*string = ft_strjoin(*string, ft_itoa((int)data));
	if (*format == 'i')
		*string = ft_strjoin(*string, ft_itoa((int)data));
	if (*format == 'o')
		*string = ft_strjoin(*string, ft_itoa(ft_int_base((int)data, 8)));
	if (*format == 'u')
		*string = ft_strjoin(*string, ft_itoa((int)data));
	if (*format == 'x')
		*string = ft_strjoin(*string, ft_dec_to_hex((int)data, 'l'));
	if (*format == 'X')
		*string = ft_strjoin(*string, ft_dec_to_hex((int)data, 'u'));
	if (*format == 'c')
		*string = ft_addchar(*string, (unsigned char)data);
	if (width.width != 0)
		*string = ft_set_width(*string, width);
	return (ft_strlen(*string));
}

int			ft_set_size(const char *format, va_list arg, char **string, t_mini width)
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
