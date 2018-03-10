
#include "includes/libft.h"

static char		*ft_set_width(t_mini *width)
{
	char 	*spaces = NULL;
	char 	*string = NULL;
	int 	i;

	i = ft_strlen(width->string);
//	char 	*string = NULL;
//
//	string = ft_strdup(str);
//	if (str)
//		ft_strdel(&str);
	if (i >= width->width)
		return (width->string);
	else if (width->sign == 1)
	{
		spaces = (width->type == 1) ? ft_string_of_zeros(width->width - i) :
				 ft_string_of_spaces(width->width - i);
		string = ft_strjoin(width->string, spaces);
	}
	else if (width->sign == 0)
	{
		spaces = (width->type == 1) ? ft_string_of_zeros(width->width - i) :
				 ft_string_of_spaces(width->width - i);
		string = ft_strjoin(spaces, width->string);
	}
	else
		return (width->string);
	ft_strdel(&spaces);
	ft_strdel(&width->string);
	return (string);
}

void 			ft_convert(va_list arg, t_mini *mini)
{
	if (mini->conv.s)
		mini->string = ft_strdup(va_arg(arg, char*));
	if (mini->conv.d)
		mini->string = ft_itoa(va_arg(arg, int));
	if (mini->conv.i)
		mini->string = ft_itoa(va_arg(arg, int));
	if (mini->conv.o)
		mini->string = ft_itoa(ft_int_base(va_arg(arg, int), 8));
	if (mini->conv.u)
		mini->string = ft_itoa(va_arg(arg, unsigned int));
	if (mini->conv.x)
		mini->string = ft_dec_to_hex(va_arg(arg, int), 'l');
	if (mini->conv.X)
		mini->string = ft_dec_to_hex(va_arg(arg, int), 'u');
	if (mini->conv.c)
	{
		ft_putchar(va_arg(arg, int));
		return ;
	}
	if (mini->width != 0)
		mini->string = ft_set_width(mini);
	ft_putstr(mini->string);
	ft_strdel(&mini->string);
}


//int			ft_set_size(const char *format, va_list arg, char **string, t_mini width)
//{
//	void	*data = NULL;
//	int 	len;
//
//	len = 0;
//	if (*format == 'l')
//	{
////		if (*++format == 'l')
////			data = (long long int *)va_arg(arg, long long int);
////		else
//		data = (long int *)va_arg(arg, long int);
//	}
//	if (*format == 'h')
//	{
////		if (*++format == 'h')
////			data = (long long int *)va_arg(arg, long long int);
////		else
//		data = (short int *) va_arg(arg, short int *);
//	}
//	if (*format == 'j')
//		data = (intmax_t *)va_arg(arg, intmax_t);
//	if (*format == 'z')
//		data = (size_t *)va_arg(arg, size_t);
//	if (ft_strchr("cCsSpdDioOuUxX", *++format))
//		len = ft_convert_size_set(data, format, string, width);
//	return (len);
//}
