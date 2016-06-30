/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 11:49:20 by tfolly            #+#    #+#             */
/*   Updated: 2016/06/30 11:56:06 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file_ls	*ft_new_file()
{
	t_file_ls	*new_file;

	new_file = (t_file_ls*)ft_memalloc(sizeof(t_file_ls));
	new_file->name = 0;
	new_file->path = 0;
	new_file->type = 0;
	new_file->size = 0;
	new_file->user = 0;
	new_file->group = 0;
	new_file->rights = 0;  // rights et type de fichier idem ?
	new_file->edtime = 0;
	new_file->next = 0;
	return (new_file);
}
