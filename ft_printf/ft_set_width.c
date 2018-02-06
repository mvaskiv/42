
#include "ft_printf.h"

char	*ft_set_width(va_list arg, const char *format, char *string, int width)
{
	char 	*spaces = NULL;

	if (ft_strlen(string) > ft_intpositive(width))
		return (string);
	else if (width < 0)
	{
		spaces = ft_string_of_spaces(ft_intpositive(width) - ft_strlen(string));
		string = ft_strjoin(string, spaces);
	}
	else if (width > 0)
	{
		spaces = ft_string_of_spaces(ft_intpositive(width) - ft_strlen(string));
		string = ft_strjoin(spaces, string);
	}
	else
		return (string);
	return (string);
}
