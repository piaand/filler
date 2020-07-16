/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:03:02 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/16 17:15:22 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

/*
** Gives the player and opponet x or o depending their player number
*/

void	set_player(t_map *map, char *line)
{
	map->player = 'x';
	map->opponent = 'o';
	(void)line;
}

/*
** Inits the player by assigning memort and setting the values
*/

void	init_player(t_map **map, t_piece **piece)
{
	//TODO malloc space	
	map->read = 0;
	piece->read = 0;
}

/*
** Reads the standard output as long as there is something to read to finds the
** keyword 'fin:' from the result.
*/

int		main(void)
{
	int		ret;
	char	*str;
	t_map	*map;
	t_piece	*piece;

	init_player(&map, &piece);
	while ((ret = get_next_line(1, &str)) > 0 &&
	!(ft_strnstr("fin:", str, BUFF_SIZE)))
	{
		if (ft_strnstr("$$$ exec", str, BUFF_SIZE))
			set_player(map, str);
		else if (!(map->read))
			read_map(str, &map);
		else if (!(piece->read))
			read_piece(str, &piece);
		else
			place_piece(&map, &piece);
	}
	return (0);
}
