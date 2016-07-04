/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upr_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:54:51 by thibault          #+#    #+#             */
/*   Updated: 2016/07/04 15:03:07 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_upr_opt(t_file_ls *list)
{
	char	*full_path;

	while (list)
	{
		if (*(list->rights) == 'd')
		{
			full_path = ft_strjoin(path, "/");
			full_path = ft_strjoin(full_path, file->name);
			list->sub = ft_file_list(list->full_path);
		}
		list = list->next;
	}
}
