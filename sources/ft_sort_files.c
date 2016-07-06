/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 14:29:32 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/06 15:43:34 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// penser a mettre le typedef dans le .h et a static les fct


static int	ft_time_sort(t_file_ls *file1, t_file_ls *file2)
{
	if (time(&file1->edtime) > time(&file2->edtime))
		return (1);
	return (0);
}

static int	ft_alpha_sort(t_file_ls *file1, t_file_ls *file2)
{
	if (ft_strcmp(file1->name, file2->name) < 0)
		return (1);
	return (0);
}

static int	ft_file_cmp(t_file_ls *file1, t_file_ls *file2, t_opt_ls *opt)
{
	t_sort_func	*sort_func;

	if (opt->t)
		sort_func = ft_time_sort;
	else
		sort_func = ft_alpha_sort;
	return (sort_func(file1, file2));
}

static int	ft_file_sorted(t_file_ls *file, t_opt_ls *opt)
{
	while (file && file->next)
	{
		if (!ft_file_cmp(file, file->next, opt))
			return (0);
		file = file->next;
	}
	return (1);
}

t_file_ls	*ft_sort_files(t_file_ls *file, t_opt_ls *opt)
{
	t_file_ls	*start;
	t_file_ls	*save;
	// t_file_ls	*tmp;

	start = file;
	save = 0;
	while (!ft_file_sorted(start, opt))
	{
		file = start;
		save = 0;
		while (file && file->next)
		{
			if (!ft_file_cmp(file, file->next, opt))
			{
				// tmp = file->next;
				if (!save)
				{
					start = file->next;
					file->next = file->next->next;
					start->next = file;
				}
				else
				{
					save->next = file->next;
					file->next = file->next->next;
					file->next->next = file;
				}
			}
		save = file;
		file = file->next;
		}
	}
	return (start);
}
