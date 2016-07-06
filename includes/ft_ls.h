/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:16:09 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/06 16:58:55 by tfolly           ###   ########.fr       */
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
# include <time.h>


typedef struct		s_opt_ls
{
	int				l;
	int				a;
	int				up_r;
	int				r;
	int				t;
	int				z;
}					t_opt_ls;

typedef struct			s_file_ls
{
	char				*name;
	char				*path;
	char				type;
	int					size;
	unsigned int		links;
	char				*user;
	char				*group;
	char				*rights;  // rights et type de fichier idem ?
	time_t 				edtime;
	struct s_file_ls	*next;
	struct s_file_ls	*sub;
}						t_file_ls;

t_file_ls				*ft_new_file();
t_file_ls				*ft_file_list(char *rep, t_opt_ls *opt);
int						ft_file_info(char *path, t_file_ls *file);
int						ft_print_file_info(t_file_ls *file, t_opt_ls *opt);

char					*ft_rights_str(struct stat *buf);
t_opt_ls				*ft_read_ls_opt(char *av1, t_opt_ls *opt);
void					ft_error_ls(char *str);
void					ft_print_all_files(t_file_ls *file, t_opt_ls *opt);
void					ft_upr_opt(t_file_ls *list, t_opt_ls *opt);
int						ft_is_dot_file(char *filename);
t_file_ls				*ft_sort_files(t_file_ls *file, t_opt_ls *opt);
t_opt_ls				*ft_opt_init(void);

typedef int (t_sort_func)(t_file_ls *file1, t_file_ls *file2);

#endif
