/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extended.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:04:13 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 15:04:29 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_read_link(t_files *files)
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
