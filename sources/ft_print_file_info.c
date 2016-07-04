/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 13:16:49 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/04 15:08:04 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_print_file_info(t_file_ls *file)
{
	ft_printf("%s", file->rights);
	ft_putstr("  ");
	ft_printf("%10s", file->user);
	ft_putstr("  ");
	ft_printf("%10s", file->group);
	ft_putstr("  ");
	ft_printf("%s", file->name);
	// ft_printf("%s:\n", file->path);
	ft_putendl("");
	return (0);
}
