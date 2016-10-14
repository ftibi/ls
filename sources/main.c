/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:52:48 by thibault          #+#    #+#             */
/*   Updated: 2016/10/14 18:12:06 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//donc on peut essayer de faire une boucler sur les arguments
#include "../includes/ft_ls.h"

static int	main_loop(t_opt_ls *opt, t_file_ls *file)
{
	blkcnt_t	*total;

	if (!(total = (blkcnt_t*)ft_memalloc(sizeof(blkcnt_t))))
		ft_error_ls("malloc");
	ft_total_block(file, total);
	if (opt->l)
		ft_printf("total %ld\n", (long)*total);
	ft_print_all_files(file, opt);
	return (1);
}

int		 main(int ac, char **av)
{
	t_file_ls	*file;
	t_file_ls	*filestart;
	t_opt_ls	*opt;
	int			i;

//idee pour reformater
// mettre le nom de base a "."
// si des noms de fichier sont precises, ne montrer que ceux la ?
	// opt = ft_opt_init();
	// file = ft_file_list(".", opt);
	// i = 1;
	// if (ac > 1 && *av[1] == '-')
	// {
	// 	opt = ft_read_ls_opt(av[1], opt);
	// 	i++;
	// }
	// while (i < ac)
	// {
	// 	file = ft_file_list(av[i], opt);
	// 	main_loop(opt, file);
	// 	i++;
	// }

	opt = ft_opt_init();
	file = 0;
	if (ac == 1)
		file = ft_file_list(".", opt);
	else if (ac == 2)
	{
		if (*av[1] == '-')
		{
			opt = ft_read_ls_opt(av[1], opt);
			file = ft_file_list(".", opt);
		}
		else
			file = ft_file_list(av[1], opt);
	}
	else if (ac == 3 && *av[1] == '-')
	{
		opt = ft_read_ls_opt(av[1], opt);
		file = ft_file_list(av[2], opt);
	}
	else
	{
		if (*av[1] == '-')
		{
			opt = ft_read_ls_opt(av[1], opt);
			i = 2;
		}
		else
			i = 1;
		while (i < ac)
		{
			if (!file)
			{
				file = ft_file_list(av[i], opt); //mettre un file->next?
				filestart = file;
			}
			// if (file != filestart)
			// {
			file->next = ft_file_list(av[i], opt); //mettre un file->next?
			file = file->next;
			// }
			i++;

		}
		ft_putendl("ici");
		//ici sort les dir1
		i = (*av[1] == '-') ? 2 : 1;
		file = filestart;
		while (i < ac)
		{
			ft_putstr(av[i]);
			ft_putendl(":");
			main_loop(opt, file);
			file = file->next;
			i++;
			if (i < ac)
				ft_putendl("");
		}
	}
	if (ac < 3)
		main_loop(opt, file);
	// ft_total_block(file, total);
	// ft_printf("total %ld\n", (long)*total);
	// ft_print_all_files(file, opt);

	return (0);
}
