#include "includes/libft.h"

char 	*ft_addchar(char *string, unsigned char c)
{
	char 	*str;

	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(string) + 2)))
		return (NULL);
	str = ft_strdup(string);
	str[ft_strlen(string)] = (unsigned char)c;
	str[ft_strlen(string) + 1] = '\0';
//	if (string)
//		free(string);
	return (str);
}