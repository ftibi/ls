/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:39:28 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/06 15:26:54 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include <time.h>
#include "includes/ft_ls.h"

int main(int ac, char **av)
{
	struct stat buf;

	if (ac != 2)
		ft_error_ls("missing file name");
	ft_printf("finename : %s\n", av[1]);
	if (lstat(av[1], &buf) == -1)
		ft_error_ls("stat error");
	if ((buf.st_mode & S_IFMT) == S_IFREG) //comparaison bit a bit du masque
		ft_printf("type : fichier ordinaire\n");
	else if ((buf.st_mode & S_IFMT) == S_IFLNK)
		ft_printf("type : symlink\n");
	else if ((buf.st_mode & S_IFMT) == S_IFDIR)
		ft_printf("type : repertoire\n");
	else
		ft_printf("type inconnu\n");
	ft_printf("link number : %hu\n", buf.st_nlink);
	ft_printf("user uid : %ld\n", (long)buf.st_uid);

	struct passwd *pwd;
	if (!(pwd = getpwuid(buf.st_uid)))
		ft_error_ls("no such user");
	ft_printf("username : %s\n", pwd->pw_name);

	struct group *sgroup;
	if (!(sgroup = getgrgid(buf.st_gid)))
		ft_error_ls("no group");
	ft_printf("user group : %s\n", sgroup->gr_name);

	ft_printf("last modif : %s",ctime(&buf.st_mtime)); // il faudra faire une substring ici

	ft_printf("%s\n", ft_rights_str(&buf));

	return (0);
}
