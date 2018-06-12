
#include "ft_ssl_des.h"

void				initialize_opt(t_opt *opt, int des_cbc)
{
	opt->len = 0;
	opt->encrypt = 1;
	opt->base64 = 0;
	opt->offset = 0;
	opt->fd_in = 0;
	opt->fd_out = 1;
	opt->padded = 0;
	opt->des_cbc = des_cbc;
	opt->key_flag = 0;
	opt->iv_flag = 0;
	opt->key = 0;
	opt->iv = 0;
	opt->offset = 0;
	opt->empty_read = 0;
}

static void			invalid_hexdigit(int specifier)
{
	ft_putstr("non-hex digit\ninvalid hex ");
	if (specifier == 1)
		ft_putstr("key ");
	else if (specifier == 2)
		ft_putstr("iv ");
	ft_putstr("value\n");
	exit(1);
}

void				hexstr_int(t_opt *opt, char *s, int specifier)
{
	int					i;
	unsigned long long	tmp;

	i = 0;
	while (s[i] != '\0' && i < 16)
	{
		if (s[i] >= 'a' && s[i] <= 'f')
			tmp = tmp * 16 + (10 + s[i] - 'a');
		else if (s[i] >= 'A' && s[i] <= 'F')
			tmp = tmp * 16 + (10 + s[i] - 'A');
		else if (s[i] >= '0' && s[i] <= '9')
			tmp = tmp * 16 + (s[i] - '0');
		else
			invalid_hexdigit(specifier);
		i++;
	}
	while (i++ < 16)
		tmp *= 16;
	if (specifier == 1 && (opt->key_flag = 1))
		opt->key = tmp;
	else if (specifier == 2 && (opt->iv_flag = 1))
		opt->iv = tmp;
}

static void			populate_i_o(int argc, char **argv, int j, t_opt *opt)
{
	if (j >= argc)
		errors(argv, j, 1);
	else if (ft_strcmp(argv[j - 1], "-i") == 0)
	{
		if ((opt->fd_in = open(argv[j], O_RDONLY)) < 0)
			(j < argc) ? errors(argv, j, 4) : exit(1);
	}
	else
		opt->fd_out = j;
}

void				populate_data(int argc, char **argv, t_opt *opt)
{
	int j;

	j = 2;
	while (j < argc)
	{
		if (ft_strcmp(argv[j], "-a") == 0 || ft_strcmp(argv[j], "-base64") == 0)
			opt->base64 = 1;
		else if (ft_strcmp(argv[j], "-d") == 0)
			opt->encrypt = 0;
		else if (ft_strcmp(argv[j], "-e") == 0)
			opt->encrypt = 1;
		else if (ft_strcmp(argv[j], "-i") == 0 || ft_strcmp(argv[j], "-o") == 0)
			populate_i_o(argc, argv, ++j, opt);
		else if (ft_strcmp(argv[j], "-k") == 0 && ++j)
			(j < argc) ? hexstr_int(opt, argv[j], 1) : errors(argv, j, 2);
		else if (ft_strcmp(argv[j], "-v") == 0 && ++j)
			(j < argc) ? hexstr_int(opt, argv[j], 2) : errors(argv, j, 2);
		else
			errors(argv, j, 3 * (argv[j][0] == '-'));
		j++;
	}
	if (opt->fd_out != 1 && (opt->fd_out = open(argv[opt->fd_out], O_CREAT
											| O_TRUNC | O_WRONLY, 0666)) < 0)
		exit(1);
}
