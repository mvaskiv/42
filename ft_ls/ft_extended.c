/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extended.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:04:13 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/12 12:16:14 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_read_link(t_files *files)
{
	char	*name;
	ssize_t	i;

	i = 0;
	if ((S_ISLNK(files->data->mode)))
	{
		name = (char*)malloc(sizeof(char) * 100);
		i = readlink(files->path, name, 100);
		name[i] = '\0';
		ft_mini_printf(" -> %s", name);
		ft_strdel(&name);
	}
}

void	ft_read_ext_perm(char *path)
{
	acl_t	acl;

	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if ((listxattr(path, NULL, 0, XATTR_NOFOLLOW)) > 0)
		ft_mini_printf("@ ");
	else if (acl > 0)
		ft_mini_printf("+ ");
	else
		ft_mini_printf("  ");
	free(acl);
}

char	*ft_get_uname(uid_t uid)
{
	struct passwd	*passwd;

	passwd = getpwuid(uid);
	if (passwd != NULL)
		return (passwd->pw_name);
	else
		return (NULL);
}

void	ft_print_type(t_files *files)
{
	if (S_ISDIR(files->data->mode))
		ft_putchar('d');
	else if (S_ISLNK(files->data->mode))
		ft_putchar('l');
	else if (files->data->mode & S_IFBLK)
		ft_putchar('b');
	else if (files->data->mode & S_IFIFO)
		ft_putchar('p');
	else if (S_ISCHR(files->data->mode))
		ft_putchar('c');
	else if (S_ISSOCK(files->data->mode))
		ft_putchar('s');
	else
		ft_putchar('-');
}

void	ft_sticky_bit(t_files *files)
{
	if ((files->data->mode & S_ISVTX) && (files->data->mode & S_IXOTH))
		ft_mini_printf("t");
	else if (files->data->mode & S_ISVTX)
		ft_mini_printf("T");
	else if (files->data->mode & S_IXOTH)
		ft_mini_printf("x");
	else
		ft_mini_printf("-");
}
