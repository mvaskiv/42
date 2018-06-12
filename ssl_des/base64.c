
#include "ft_ssl_des.h"

char g_b64[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
	'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
	'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
	'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
	's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2',
	'3', '4', '5', '6', '7', '8', '9', '+', '/'};

static int		get_len(unsigned char *s, int *len)
{
	int i;
	int	equal_count;

	i = 0;
	equal_count = 0;
	*len = 0;
	while (i < 4)
	{
		if (s[i] == '=')
			equal_count++;
		i++;
	}
	if (equal_count == 2)
		*len = 1;
	if (equal_count == 1)
		*len = 2;
	if (equal_count == 0)
		*len = 3;
	return (1);
}

static void		join_b64_str(t_opt *opt, unsigned char *str, int len)
{
	ft_memcpy(opt->b64_s + opt->offset, str, len);
	opt->offset += len;
}

void			b64_encrypt(unsigned char *s, t_opt *opt, int j)
{
	int				i;
	int				value;
	unsigned char	group[4];

	i = 0;
	while (i < opt->len)
	{
		j = 0;
		value = 0;
		ft_bzero(group, 4);
		while (i < opt->len && j < 3)
			value += (ft_power(256, 3 - (++j)) * (unsigned char)s[i++]);
		while (j < 3)
			group[++j] = '=';
		while (j >= 0)
		{
			group[j] = (group[j] != '=') ? g_b64[value % 64] : group[j];
			value /= 64;
			j--;
		}
		join_b64_str(opt, group, 4);
		if (i != 0 && i % 48 == 0 && group[0] && i < opt->len)
			join_b64_str(opt, (unsigned char *)"\n", 1);
	}
	(group[0]) ? join_b64_str(opt, (unsigned char *)"\n", 1) : 0;
}

/*
** v_idx_l[0] : value
** v_idx_l[1] : index
** v_idx_l[2] : (decoded) len
*/

void			b64_decrypt(unsigned char *s, t_opt *opt, int i, int j)
{
	int				v_idx_l[3];
	int				abort;
	unsigned char	group[3];

	abort = 0;
	while (i < opt->len && !abort && !(j = 0) && get_len(&s[i], &v_idx_l[2]))
	{
		v_idx_l[0] = 0;
		ft_bzero(group, 3);
		while (i < opt->len && j < 4 && !abort && !(v_idx_l[1] = 0))
		{
			i = (((i + 1) % 65 == 0) && s[i] == '\n') ? i + 1 : i;
			while (s[i] != '=' && v_idx_l[1] < 64 && g_b64[v_idx_l[1]] != s[i])
				v_idx_l[1]++;
			abort = (++i && v_idx_l[1] == 64) ? 1 : 0;
			v_idx_l[0] += ft_power(64, 4 - (++j)) * v_idx_l[1];
		}
		while (j-- >= 0)
		{
			group[j - 1] = v_idx_l[0] % 256;
			v_idx_l[0] /= 256;
		}
		(!abort) ? join_b64_str(opt, group, v_idx_l[2]) : 0;
	}
	(!abort) ? join_b64_str(opt, (unsigned char *)"\n", 1) : 0;
}


void			base64(int argc, char **argv)
{
	t_opt			opt;
	unsigned char	*s;

	initialize_opt(&opt, 0);
	populate_data(argc, argv, &opt);
	if (!(opt.b64_s = ft_memalloc(2 * opt.len)))
		exit(1);
	s = read_data(&opt, 0);
	if (!opt.empty_read)
	{
		if (opt.encrypt)
			b64_encrypt(s, &opt, 0);
		else
			b64_decrypt(s, &opt, 0, 0);
		putnstr_fd(opt.b64_s, opt.fd_out, opt.offset);
		free(opt.b64_s);
		free(s);
	}
}
