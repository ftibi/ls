/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 15:03:17 by thibault          #+#    #+#             */
/*   Updated: 2016/09/18 14:58:44 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Parcours file et l'affiche en tenant compte de l'option -R si elle est là
** Il faudrait mettre la fonction de tri ici
*/

void	ft_print_all_files(t_file_ls *file, t_opt_ls *opt)
{
	t_file_ls	*start;

	file = ft_sort_files(file, opt);
	start = file;
	while (file)
	{
		ft_print_file_info(file, opt);
		file = file->next;
	}
	file = start;
	while (file && opt->up_r)
	{
		if (*(file->rights) == 'd' && !ft_is_dot_file(file->name))
		{
			ft_printf("\n./%s:\n", file->name);
			ft_print_all_files(file->sub, opt);
		}
		file = file->next;
	}
}
