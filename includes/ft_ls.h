/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:16:09 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/04 14:57:12 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"


//a verifier
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <unistd.h>
# include <grp.h>

typedef struct		s_opt_ls
{
	int				l;
	int				a;
	int				up_r;
	int				r;
	int				t;
}					t_opt_ls;

typedef struct			s_file_ls
{
	char				*name;
	char				*path;
	char				type;
	int					size;
	char				*user;
	char				*group;
	char				*rights;  // rights et type de fichier idem ?
	int					edtime;
	struct s_file_ls	*next;
	struct s_file_ls	*sub;
}						t_file_ls;

t_file_ls				*ft_new_file();
t_file_ls				*ft_file_list(char *rep);
int						ft_file_info(char *path, t_file_ls *file);
int						print_file_info(t_file_ls *file);

char					*ft_rights_str(struct stat *buf);
int						ft_read_ls_opt(char *av1, t_opt_ls *opt);
void					ft_error_ls(char *str);

#endif
