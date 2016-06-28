/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:39:28 by tfolly            #+#    #+#             */
/*   Updated: 2016/06/28 16:12:39 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <sys/types.h>
#include <grp.h>
#include <time.h>
#include "includes/ft_ls.h"


void	ft_error_ls(char *str)
{
	ft_printf("error : %s\n", str);
	exit(0);
}

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
	t_opt_ls	*opt;

	if (ac != 2)
		ft_error_ls("");
	opt = (t_opt_ls*)ft_memalloc(sizeof(t_opt_ls));
	ft_read_ls_opt(av[1], opt);
	ft_ls_print_opt(opt);
	return (0);
}
