
#include "ft_ssl_des.h"

unsigned char	*read_data(t_opt *opt, int ret)
{
	int				read_count;
	unsigned char	buf[BUFF_SIZE + 1];
	unsigned char	*data;
	unsigned char	*tmp;

	ft_bzero(buf, BUFF_SIZE + 1);
	read_count = 0;
	while ((ret = read(opt->fd_in, buf, BUFF_SIZE)))
	{
		tmp = data;
		if (!(data = ft_memalloc(BUFF_SIZE * ++read_count)))
			exit(1);
		if (read_count > 1)
		{
			ft_memcpy(data, tmp, BUFF_SIZE * read_count);
			free(tmp);
		}
		ft_memcpy(data + BUFF_SIZE * (read_count - 1), buf, ret);
		ft_bzero(buf, BUFF_SIZE);
		opt->len += ret;
	}
	(opt->fd_in > 0) ? close(opt->fd_in) : 0;
	(opt->len == 0) ? opt->empty_read = 1 : 0;
	return (data);
}
