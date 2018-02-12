
#include "ft_printf.h"

char 	*ft_string_of_zeros(char * string, int precision)
{
	int		i;

	i = 0;
	while (i < precision && !(ft_isalnum(string[i])))
		((char *)string)[i++] = (char)'0';
	return (string);
}

char	*ft_set_width(const char *format, char *string, float width)
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
		if ((width - (int)width) > 0)
			string = ft_string_of_zeros(string, ((width - (int)width) * 10));
	}
	else
		return (string);
	return (string);
}
