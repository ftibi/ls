/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 13:16:49 by tfolly            #+#    #+#             */
/*   Updated: 2016/10/06 18:48:52 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	ft_size_fmt(unsigned int size, t_opt_ls *opt)
{
	if (size >= 1000000 && opt->z)
	{
		if (size < 10000000)
			ft_printf("%10d.%dM", size / 1000000, (size % 1000000) / 100000);
		else
			ft_printf("%12dM", size / 1000000);
	}
	else if (size >= 1000 && opt->z)
	{
		if (size < 10000)
			ft_printf("%10d.%dK", size / 1000, (size % 1000) / 100);
		else
			ft_printf("%12dK", size / 1000);
	}
	else if (opt->z)
		ft_printf("%12dB", size);
	else
		ft_printf("%11d", size);
	return (0);
}

int			ft_print_file_info(t_file_ls *file, t_opt_ls *opt)
{
	char	*mytime;

	if (!opt->a && *(file->name) == '.')
		return (0);
	if (opt->l)
	{
		mytime = ft_strsub(ctime(&file->edtime), 4, 12);
		*mytime = ft_tolower(*mytime);
		ft_printf("%s", file->rights);
		ft_putstr("  ");
		ft_printf("%3d", file->links);
		ft_putstr("  ");
		ft_printf("%10s", file->user);
		ft_putstr("  ");
		ft_printf("%10s", file->group);
		ft_putstr("  ");
		ft_size_fmt(file->size, opt);
		ft_putstr("  ");
		ft_printf("%10s", mytime);
		ft_putstr("  ");
	}
	ft_printf("%s", file->name);
	if (*(file->rights) == 'l')
	{
		char	*full_path;
		size_t	bufsize = 40;
		char	*buf = ft_memalloc(bufsize);

		full_path = ft_strjoin(file->path, "/");
		full_path = ft_strjoin(full_path, file->name);
		readlink(full_path, buf, bufsize);
		ft_printf(" -> %s ", buf);

	}
	ft_putendl("");
	return (0);
}
