/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:45:18 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/10 15:02:17 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcpy(char *dst, char const *src)
{
	char *save;

	save = dst;
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = *src;
	return (save);
}
