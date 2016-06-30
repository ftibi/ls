/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 11:48:10 by tfolly            #+#    #+#             */
/*   Updated: 2016/06/30 13:02:29 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file_ls	*ft_file_list(char *path)
{
	DIR				*dirr;
	struct dirent	*dir;
	t_file_ls		*file;

	if (!(dirr = opendir(path)))
		return (0);
	while ((dir = readdir(dirr)))
	{
		file = ft_new_file();
		file->name = ft_strdup(dir->d_name);
		ft_file_info(path, file);
		// ft_printf("%s\n", file->name);
	}
	return (file);
}
