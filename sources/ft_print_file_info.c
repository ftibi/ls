/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 13:16:49 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/06 16:02:25 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_print_file_info(t_file_ls *file, t_opt_ls *opt)
{
	char	*mytime;

	if (!opt->a && *(file->name) == '.')
		return (0);
	if (opt->l)
	{
		mytime = ft_strsub(ctime(&file->edtime), 4, 12);
		ft_printf("%s", file->rights);
		ft_putstr("  ");
		ft_printf("%d", file->links);
		ft_putstr("  ");
		ft_printf("%10s", file->user);
		ft_putstr("  ");
		ft_printf("%10s", file->group);
		ft_putstr("  ");
		ft_printf("%10s", mytime);
		ft_putstr("  ");
	}
	ft_printf("%s", file->name);
	ft_putendl("");
	return (0);
}
