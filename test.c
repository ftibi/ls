/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:39:28 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/06 16:30:06 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <sys/types.h>
#include <grp.h>
#include <time.h>
#include "includes/ft_ls.h"
#include <string.h>

void	ft_ls_print_opt(t_opt_ls *opt)
{
	if (opt->l)
		ft_printf("l\n");
	if (opt->a)
		ft_printf("a\n");
	if (opt->up_r)
		ft_printf("R\n");
	if (opt->r)
		ft_printf("r\n");
	if (opt->t)
		ft_printf("t\n");

}

int main(int ac, char **av)
{
	t_file_ls	*file;
	t_opt_ls	*opt;

	opt = ft_opt_init();
	if (ac == 1)
		file = ft_file_list(".", opt);
	else if (ac == 2)
		file = ft_file_list(av[1], opt);
	else //if (ac == 3)
	{
		opt = ft_read_ls_opt(av[1], opt);
		file = ft_file_list(av[2], opt);
	}
	ft_print_all_files(file, opt);
	// while (file)
	// {
	// 	ft_printf("%s\n", file->name);
	// 	file = file->next;
	// }
	return (0);
}
