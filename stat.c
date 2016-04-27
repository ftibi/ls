/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:39:28 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/27 18:22:39 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>

void	ft_error(char *str)
{
	printf("error : %s\n", str);
	exit(0);
}

int main(int ac, char **av)
{
	struct stat buf;

	if (ac != 2)
		ft_error("missing file name");
	printf("finename : %s\n", av[1]);
	if (stat(av[1], &buf) == -1)
		ft_error("stat error");
	if ((buf.st_mode & S_IFMT) == S_IFREG) //comparaison bit a bit du masque
		printf("fichier ordinaire\n");
	else if ((buf.st_mode & S_IFMT) == S_IFDIR)
		printf("repertoire\n");
	else
		printf("type inconnu\n");
	printf("link number : %hu\n", buf.st_nlink);
	printf("user uid : %ld\n", (long)buf.st_uid);
	
	struct passwd *pwd;
	if (!(pwd = getpwuid(buf.st_uid)))
		ft_error("no such user");
	printf("username : %s\n", pwd->pw_name);

	struct group *sgroup;
	if (!(sgroup = getgrgid(buf.st_gid)))
		ft_error("no group");
	printf("user group : %s\n", sgroup->gr_name);

	return (0);
}
