/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_ls_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 17:24:47 by tfolly            #+#    #+#             */
/*   Updated: 2016/06/26 17:52:46 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h> // A ENLEVER DES QUE FT_PRINTF

static void	ft_illegal_opt(char c)
{
	printf("ls: illegal option -- %c\n", c);
}

static int	ft_is_in_tab(char c, char *tab, int tab_size)
{
	int	i;

	i = 0;
	while (i < tab_size)
	{
		if (tab[i] == c)
			return (i);
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

int			ft_read_ls_opt(char *av1, t_opt_ls *opt)
{
	const char	opt_tab[5] = "lRart";
	int			i;

	if (av1[0] != '-')
		return (0);
	i = 0;
	while (*av1)
	{
		if (!ft_is_in_tab(*av1, (char*)&opt_tab, 5))
			ft_illegal_opt(*av1);
		update_opt(opt, *av1, (ft_is_in_tab(*av1, (char*)&opt_tab, 5)) ? 1 : 0);
		av1++;
	}
	return (0);
}
