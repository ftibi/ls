/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rights_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 15:20:30 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/04 14:51:47 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
//user/group/others
// c char device b block device
static char	file_type(struct stat buf) // rajouter tube/pipe FIFO
{
	if ((S_IFMT & buf.st_mode) == S_IFSOCK) //socket
		return ('s');
	if ((S_IFMT & buf.st_mode) == S_IFLNK)
		return ('l');
	if ((S_IFMT & buf.st_mode) == S_IFREG)
		return ('-');
	if ((S_IFMT & buf.st_mode) == S_IFBLK)//peripherique bloc
		return ('b');
	if ((S_IFMT & buf.st_mode) == S_IFDIR)
		return ('d');
	if ((S_IFMT & buf.st_mode) == S_IFCHR) //peripherique caractere
		return ('c');
	if ((S_IFMT & buf.st_mode) == S_IFIFO) //peripherique caractere
		return ('p');
	return ('-');								//type unknown??
}

static void ft_perm(char *str, struct stat buf)
{
	str[1] = (S_IRUSR & buf.st_mode) ? 'r' : '-';
	str[2] = (S_IWUSR & buf.st_mode) ? 'w' : '-';
	str[3] = (S_IXUSR & buf.st_mode) ? 'x' : '-';
	str[4] = (S_IRGRP & buf.st_mode) ? 'r' : '-';
	str[5] = (S_IWGRP & buf.st_mode) ? 'w' : '-';
	str[6] = (S_IXGRP & buf.st_mode) ? 'x' : '-';
	str[7] = (S_IROTH & buf.st_mode) ? 'r' : '-';
	str[8] = (S_IWOTH & buf.st_mode) ? 'w' : '-';
	str[9] = (S_IXOTH & buf.st_mode) ? 'x' : '-';
}

/*
** Renvoit une chaine de caracteres qui contient le type de fichier et les droits
*/

char	*ft_rights_str(struct stat *buf)
{
	char	*str;

	if (!(str = (char*)ft_memalloc(11)))
		;//ft_error("malloc error");
	str[0] = file_type(*buf);
	ft_perm(str, *buf);
	return (str);
}
