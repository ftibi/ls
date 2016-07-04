/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_ls_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 17:24:47 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/04 15:34:34 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_illegal_opt(char c)
{
	ft_printf("ls: illegal option -- %c\n", c);
}

static int	ft_is_in_tab(char c, char *tab, int tab_size)
{
	int	i;

	i = 0;
	while (i < tab_size)
	{
		if (tab[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	update_opt(t_opt_ls *opt, char c, int val)
{
	if (c == 'l')
		opt->l = val;
	if (c == 'R')
		opt->up_r = val;
	if (c == 'a')
		opt->a = val;
	if (c == 'r')
		opt->r = val;
	if (c == 't')
		opt->t = val;
}

t_opt_ls		*ft_read_ls_opt(char *av1)
{
	const char	opt_tab[5] = "lRart";
	t_opt_ls	*opt;

	if (!av1 || av1[0] != '-')
		return (0);
	if (!(opt = (t_opt_ls*)ft_memalloc(sizeof(t_opt_ls))))
		ft_error_ls("malloc error\n");
	av1++;
	while (*av1)
	{
		if (!ft_is_in_tab(*av1, (char*)&opt_tab, 5))
			ft_illegal_opt(*av1);
		update_opt(opt, *av1, (ft_is_in_tab(*av1, (char*)&opt_tab, 5)) ? 1 : 0);
		av1++;
	}
	return (opt);
}
