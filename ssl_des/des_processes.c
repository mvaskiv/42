
#include "ft_ssl_des.h"

void		encrypt_b64_and_print(t_opt *opt)
{
	unsigned char *tmp;

	if (!(tmp = ft_memalloc(opt->offset)))
		exit(1);
	ft_memcpy(tmp, opt->b64_s, opt->offset);
	ft_bzero(opt->b64_s, opt->offset);
	opt->len = opt->offset;
	opt->offset = 0;
	b64_encrypt(tmp, opt, 0);
	putnstr_fd(opt->b64_s, opt->fd_out, opt->offset);
	opt->len = 0;
	free(tmp);
	free(opt->b64_s);
}

void		remove_padding_for_decryption(unsigned long long *s_blk, int *len)
{
	int	j;

	j = *s_blk % 256;
	if (j > 0 && j <= 8)
	{
		*s_blk = (j == 8) ? 0 : *s_blk / ft_power(256, j) * ft_power(256, j);
		*len = 8 - j;
	}
}

void		des_processes(unsigned long long s_blk, t_opt *opt)
{
	unsigned char	blk[9];
	int				j;
	int				len;

	ft_bzero(blk, 9);
	len = 8;
	if (!opt->encrypt)
		remove_padding_for_decryption(&s_blk, &len);
	if (s_blk != 0)
	{
		if (opt->des_cbc && opt->encrypt)
			opt->iv = s_blk;
		j = 8;
		while (--j >= 0)
			blk[7 - j] = s_blk / ft_power(256, j) % 256;
		if (opt->encrypt && opt->base64)
		{
			ft_memcpy(opt->b64_s + opt->offset, blk, 8);
			opt->offset += 8;
			if (opt->padded)
				encrypt_b64_and_print(opt);
		}
		else
			putnstr_fd(blk, opt->fd_out, len);
	}
}
