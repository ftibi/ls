/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:52:48 by thibault          #+#    #+#             */
/*   Updated: 2016/10/07 18:50:50 by thibaultfolly    ###   ########.fr       */
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
	t_opt_ls	*opt;
	int			i;

//idee pour reformater
// mettre le nom de base a "." et le changer que si un param autre que les options est entré
// il faut definitivement refaire ca de maniere plus elegante
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
	if (ac == 1)
		file = ft_file_list(".", opt);
	else if (ac == 2)
	{
		file = ft_file_list(".", opt);
		if (*av[1] == '-')
			opt = ft_read_ls_opt(av[1], opt);
		else
			file = ft_file_list(av[1], opt);
	}
	else if (ac == 3)
	{
		if (*av[1] == '-')
			opt = ft_read_ls_opt(av[1], opt);
		file = ft_file_list(av[2], opt);
	}
	else
	{
		opt = ft_read_ls_opt(av[1], opt);
		i = 2;
		while (i < ac)
		{
			ft_putstr(av[i]);
			ft_putendl(":");
			file = ft_file_list(av[i], opt);
			main_loop(opt, file);
			i++;
			if (i < ac)
				ft_putendl("");
		}
	}
	if (ac <= 3)
		main_loop(opt, file);
	// ft_total_block(file, total);
	// ft_printf("total %ld\n", (long)*total);
	// ft_print_all_files(file, opt);

	return (0);
}
