/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 15:03:17 by thibault          #+#    #+#             */
/*   Updated: 2016/07/04 15:24:22 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Parcours file et l'affiche en tenant compte de l'option -R si elle est là
*/

void	ft_print_all_files(t_file_ls *file, t_opt_ls *opt)
{
	t_file_ls	*start;

	start = file;
	while (file)
	{
		ft_print_file_info(file);
		file = file->next;
	}
	file = start;
	while (file)
	{
		if (*(file->rights) == 'd')
		{
			ft_print_all_files(file->sub, opt);
		}
		file = file->next;
	}
}
