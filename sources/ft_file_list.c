/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 11:48:10 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/04 14:50:01 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Lit un chemin, renvoit une liste chainee qui contient tous les fichiers
** trouvés à cette addresse
*/

t_file_ls	*ft_file_list(char *path)
{
	DIR				*dirr;
	struct dirent	*dir;
	t_file_ls		*file;
	t_file_ls		*start;

	if (!(dirr = opendir(path)))
		return (0);
	file = 0;
	while ((dir = readdir(dirr)))
	{
		if (!file)
		{
			file = ft_new_file();
			start = file;
		}
		else
		{
			file->next = ft_new_file();
			file = file->next;
		}
		file->name = ft_strdup(dir->d_name);
		ft_file_info(path, file);
		// ft_printf("%s\n", file->name);
	}
	return (start);
}
