/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 11:48:10 by tfolly            #+#    #+#             */
/*   Updated: 2016/10/14 17:32:18 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Lit un chemin, renvoit une liste chainee qui contient tous les fichiers
** trouvés à cette addresse
*/

t_file_ls	*ft_file_list(char *path, t_opt_ls *opt)
{
	DIR				*dirr;
	struct dirent	*dir;
	t_file_ls		*file;
	t_file_ls		*start;
	char			*full_path;

	if (!(dirr = opendir(path)))// c'est ici que je dois faire appel a sterror
	{
		//ici il faut que je verifie que c'est un dir, si ce n;est pas un dir
		//je peux me contenter dafficher le nom
		// if ()
		// ft_printf("ls: %s: ", path);
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		return (0);
	}
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
		if (opt && opt->up_r && !ft_is_dot_file(file->name) && *(file->rights) == 'd')
		{
			full_path = ft_strjoin(file->path, "/");
			full_path = ft_strjoin(full_path, file->name);
			// exit(0);
			file->sub = ft_file_list(full_path, opt);
		}
			// ft_upr_opt(file, opt);
		// ft_printf("%s\n", file->name);
	}
	return (start);
}
