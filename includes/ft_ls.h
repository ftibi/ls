/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:16:09 by tfolly            #+#    #+#             */
/*   Updated: 2016/06/26 17:28:03 by tfolly           ###   ########.fr       */
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

char	*ft_rights_str(struct stat *buf);

#endif
