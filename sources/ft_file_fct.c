/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 11:49:20 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/06 17:29:06 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file_ls	*ft_new_file(void)
{
	t_file_ls	*new_file;

	if (!(new_file = (t_file_ls*)ft_memalloc(sizeof(t_file_ls))))
		ft_error_ls("malloc error\n");
	new_file->name = 0;
	new_file->path = 0;
	new_file->type = 0;
	new_file->size = 0;
	new_file->user = 0;
	new_file->group = 0;
	new_file->rights = 0;  // rights et type de fichier idem ?
	new_file->edtime = 0;
	new_file->next = 0;
	new_file->sub = 0;
	new_file->blocks = 0;
	new_file->links = 0;
	return (new_file);
}
