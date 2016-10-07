/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 14:29:32 by tfolly            #+#    #+#             */
/*   Updated: 2016/10/07 17:47:33 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


static int	ft_time_sort(t_file_ls *file1, t_file_ls *file2)
{
	time_t	*time1;
	time_t	*time2;

	if (!(time1 = (time_t*)ft_memalloc(sizeof(time_t))))
		ft_error_ls("malloc error");
	if (!(time2 = (time_t*)ft_memalloc(sizeof(time_t))))
		ft_error_ls("malloc error");

	time1 = ft_memcpy(time1, &(file1->edtime), sizeof(time1));
	time2 = ft_memcpy(time2, &(file2->edtime), sizeof(time2));

	if (*time1 >= *time2) //ici il faudra free time1 et time2
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
	// ft_putendl("filecmp");

	if (opt->t)
		sort_func = ft_time_sort;
	else
		sort_func = ft_alpha_sort;
	return ((opt->r) ? !sort_func(file1, file2) : sort_func(file1, file2));//return un ternaire en fct de opt
}

static int	ft_file_sorted(t_file_ls *file, t_opt_ls *opt)
{
	while (file && file->next)
	{
		if (!ft_file_cmp(file, file->next, opt))
			return (0);
		file = file->next;
	// ft_printf("name : %s\n", file->name);
	// ft_printf("name : %s\n", file->next->name);
	}
	return (1);
}

t_file_ls	*ft_sort_files(t_file_ls *file, t_opt_ls *opt)
{
	t_file_ls	*start;
	t_file_ls	*save;
	t_file_ls	*tmp;

	start = file;
	save = 0;
	while (!ft_file_sorted(start, opt))
	{
		file = start;
		save = 0;
		while (file && file->next) //c ce while la qui boucle
		{
			if (!ft_file_cmp(file, file->next, opt))
			{
				// tmp = file->next;
				if (!save)
				{
					save = file;
					tmp = file->next->next;
					file = file->next;
					file->next = save;
					file->next->next = tmp;

					start = file;
				}
				else
				{
					tmp = file->next->next;
					save->next = file->next;
					save->next->next = file;
					save->next->next->next = tmp;

				}
			}
			save = file;
			file = file->next;
		}
	}
	return (start);
}
