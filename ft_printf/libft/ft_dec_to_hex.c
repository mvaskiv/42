
#include "includes/libft.h"

char		*ft_dec_to_hex(int number, char c)
{
	char	*output;
	int 	position;
	int 	remainder;
	int		letter_case;

	output = ft_strnew(3);
	position = 0;
	if (c == 'u')
		letter_case = 55;
	if (c == 'l')
		letter_case = 87;
	while (number)
	{
		remainder = number % 16;
		if (remainder < 10)
			output[position] = (char)remainder + 48;
		if (remainder >= 10)
			output[position] = (char)remainder + letter_case;
		position++;
		number /= 16;
	}
	output[position] = '\0';
	return (ft_strrev(output));
}

