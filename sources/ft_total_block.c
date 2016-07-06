/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_total_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 17:13:53 by tfolly            #+#    #+#             */
/*   Updated: 2016/07/06 17:45:41 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_total_block(t_file_ls *file, blkcnt_t *total)
{
	t_file_ls	*start;

	start = file;
	while (file)
	{
		*total += file->blocks;
		file = file->next;
	}
	file = start;
	while (file)
	{
		if (*(file->name) == 'd')
		{
			ft_total_block(file->sub, total);
		}
		file = file->next;
	}
}
