/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 11:48:10 by tfolly            #+#    #+#             */
/*   Updated: 2016/06/30 12:18:35 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file_ls	*ft_file_list(char *rep)
{
	DIR				*dirr;
	struct dirent	*dir;
	t_file_ls		*file;

	if (!(dirr = opendir(rep)))
		return (0);
	while((dir = readdir(dirr)))
	{
		file = ft_new_file();
		file->name = ft_strdup(dir->d_name);
		ft_printf("%s\n", file->name);
	}

	return (file);
}
