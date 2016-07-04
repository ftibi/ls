/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upr_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:54:51 by thibault          #+#    #+#             */
/*   Updated: 2016/07/04 15:14:50 by thibaultfolly    ###   ########.fr       */
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
			full_path = ft_strjoin(list->path, "/");
			full_path = ft_strjoin(full_path, list->name);
			list->sub = ft_file_list(full_path);
		}
		list = list->next;
	}
}
