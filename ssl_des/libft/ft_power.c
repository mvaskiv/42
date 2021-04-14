
#include "includes/libft.h"

long long		ft_power(long long nbr, int power)
{
	if (power < 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (1);
	}
	else if (power >= 2)
	{
		nbr *= ft_power(nbr, power - 1);
	}
	return (nbr);
}
