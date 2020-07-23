/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:46:21 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/23 11:22:17 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Takes x and y coordinates as integers and turns them into a string that
** prints out to the standard output.
*/

void print_coordinates(int y, int x)
{
	ft_putnbr_fd(y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(x, 1);
	ft_putchar_fd('\n', 1);
}

/*
** Removes space from given char array.
*/

void	clear_array(char **array, int amount)
{
	int i;

	i = 0;
	while(i < amount)
	{
		ft_strdel(&array[i]);
		i++;
	}
	free(array);
}

/*
** Clears the map and piece so new ones from next turn can be read.
*/

void	clear_map_piece(t_map **map, t_piece **piece)
{
	clear_array((*(map))->layout, (*(map))->row);
	clear_array((*(piece))->layout, (*(piece))->row);
	(*(map))->layout = NULL;
	(*(piece))->layout = NULL;
	(*(map))->read = 0;
	(*(piece))->read = 0;
}

int	place_piece(t_map **map, t_piece **piece, t_player **player)
{
	print_coordinates(3, 3);
	(*(player))->turn++;
	clear_map_piece(map, piece);
	write_to_log("Cleared map and piece.");
	return(1);
}
