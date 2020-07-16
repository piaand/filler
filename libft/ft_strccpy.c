/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:30:39 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/16 15:24:27 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** Copies the strng src to dst untill the characte c is found or the src
** runs out. Doesn't include the character found, returns the head of dest
*/

size_t	ft_strccpy(char *dst, const char *src, int c)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
