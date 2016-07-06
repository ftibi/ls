/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 13:16:49 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/06 15:34:57 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_print_file_info(t_file_ls *file)
{
	char	*mytime;

	// mytime = ctime(&file->edtime);
	mytime = ft_strsub(ctime(&file->edtime), 4, 12);
	ft_printf("%s", file->rights);
	ft_putstr("  ");
	ft_printf("%10s", file->user);
	ft_putstr("  ");
	ft_printf("%10s", file->group);
	ft_putstr("  ");
	ft_printf("%10s", mytime);
	ft_putstr("  ");
	ft_printf("%s", file->name);
	// ft_printf("%s:\n", file->path);
	ft_putendl("");
	return (0);
}
