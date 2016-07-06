/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:03:19 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/06 16:59:45 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_opt_ls	*ft_opt_init(void)
{
	t_opt_ls	*opt;

	if (!(opt = (t_opt_ls*)ft_memalloc(sizeof(t_opt_ls))))
		ft_error_ls("malloc error");
	opt->l = 0;
	opt->a = 0;
	opt->up_r = 0;
	opt->r = 0;
	opt->t = 0;
	opt->z = 0;
	return (opt);
}
