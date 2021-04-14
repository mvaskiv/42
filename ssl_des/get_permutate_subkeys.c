
#include "ft_ssl_des.h"

int		g_pc1[] = {57, 49, 41, 33, 25, 17, 9,
	1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27,
	19, 11, 3, 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15,
	7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29,
	21, 13, 5, 28, 20, 12, 4};

int		g_rot[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

int		g_pc2[] = {14, 17, 11, 24, 1, 5,
	3, 28, 15, 6, 21, 10,
	23, 19, 12, 4, 26, 8,
	16, 7, 27, 20, 13, 2,
	41, 52, 31, 37, 47, 55,
	30, 40, 51, 45, 33, 48,
	44, 49, 39, 56, 34, 53,
	46, 42, 50, 36, 29, 32};

static int		rotate(unsigned int num, int i)
{
	int dropped;
	int	rot;

	rot = 0;
	while (rot < g_rot[i])
	{
		dropped = (num >> (32 - 1 - 4)) & 1;
		num = (num << 1) | dropped;
		rot++;
	}
	num %= 268435456;
	return (num);
}

void			get_permutate_subkeys(t_opt *opt, unsigned long long *subkeys)
{
	unsigned int		c;
	unsigned int		d;
	int					i;

	i = 0;
	opt->key = permutate(opt->key, g_pc1, 56, 64);
	c = opt->key / 268435456;
	d = opt->key % 268435456;
	while (i < 16)
	{
		c = rotate(c, i);
		d = rotate(d, i);
		subkeys[i] = (unsigned long long)(c) * 268435456 + d;
		subkeys[i] = permutate(subkeys[i], g_pc2, 48, 56);
		i++;
	}
}
