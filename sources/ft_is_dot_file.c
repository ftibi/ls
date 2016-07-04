/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dot_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 16:44:32 by thibault          #+#    #+#             */
/*   Updated: 2016/07/04 17:54:59 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_is_dot_file(char *filename)
{
	if (ft_strcmp(filename, ".") && ft_strcmp(filename, ".."))
		return (0);
	return (1);
}
