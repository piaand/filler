/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 08:31:49 by pandersi          #+#    #+#             */
/*   Updated: 2020/03/23 11:59:12 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_itoa(int n)
{
	char	*ascii;
	long	i;
	int		len;

	i = n;
	len = ft_count_nbr_length(i);
	if (!(ascii = ft_strnew(len)))
		return (NULL);
	if (i < 0)
	{
		ascii[0] = '-';
		i *= -1;
	}
	else if (i == 0)
		ascii[0] = '0';
	while (i > 0)
	{
		ascii[--len] = (i % 10) + '0';
		i /= 10;
	}
	return (ascii);
}
