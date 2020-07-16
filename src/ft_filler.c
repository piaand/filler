/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:03:02 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/16 15:35:47 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

int	main(void) {
	
	int i;
	int count;
	char *str;

	count = 0;
	while((i = get_next_line(1, &str)) > 0)
	{
		if (count == 0)
		{
			ft_putendl_fd("3 3", 1);
			count = 1;
		}
		if (ft_strnstr("Piece", str, 100))
		{
			count = 0;
		}
	}
	return (0);
}
