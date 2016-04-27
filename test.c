/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:39:28 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/27 17:12:50 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_error(char *str)
{
	printf("error : %s\n", str);
	exit(0);
}

int main(int ac, char **av)
{
	DIR *dir;
	struct dirent *entry;

	if (ac != 2)
		ft_error("missing dir name");
	if (!(dir = opendir(av[1])))
			ft_error("can't open directory");
	while ((entry = readdir(dir)))
		printf("%s\n", entry->d_name);
	closedir(dir);




	return (0);
}
