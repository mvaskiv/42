/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_extended.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:37:19 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 19:04:48 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_l_link(char *path)
{
	t_files		*one_for_link;
	t_l_out		widths;

	one_for_link = (t_files *)malloc(sizeof(t_files));
	one_for_link->data = (t_data *)malloc(sizeof(t_data));
	one_for_link->name = path;
	ft_write_l_stats(&one_for_link, path);
	ft_set_cols(one_for_link, &widths);
	ft_read_list(one_for_link, widths);
	free(one_for_link->data);
	free(one_for_link->path);
	free(one_for_link);
	one_for_link = NULL;
}

void	ft_set_uid(t_files *files)
{
	if ((files->data->mode & S_ISUID) && (files->data->mode & S_IEXEC))
		ft_mini_printf("s");
	else if (files->data->mode & S_ISUID)
		ft_mini_printf("S");
	else if (files->data->mode & S_IEXEC)
		ft_mini_printf("x");
	else
		ft_mini_printf("-");
}