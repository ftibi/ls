/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 12:26:54 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/04 15:16:54 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Remplit les infos d'un element de la liste chainee
*/


int		ft_file_info(char *path, t_file_ls *file)
{
	char		*full_path;
	struct stat	*buf;
	int			status;
	struct passwd *pwd;
	struct group *sgroup;

	if (!(buf = (struct stat*)ft_memalloc(sizeof(struct stat))))
		return (0);
	full_path = ft_strjoin(path, "/");
	full_path = ft_strjoin(full_path, file->name);
	status = lstat(full_path, buf);
	path = ft_strjoin("./", path); //pas forcement necessaire
	file->path = ft_strdup(path);
	file->rights = ft_rights_str(buf);
	if (!(pwd = getpwuid(buf->st_uid)))
		return (0);// ft_error_ls("no such user");
	file->user =  pwd->pw_name;
	if (!(sgroup = getgrgid(buf->st_gid)))
		return (0);// ft_error_ls("no group");
	file->group = sgroup->gr_name;
	//il manque le temps
	// ft_print_file_info(file);
	return (0);
}
