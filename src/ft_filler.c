/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:03:02 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/22 11:25:17 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

/*
** Gives the player and opponet x or o depending their player number
*/

void	set_player(t_player **player)
{
	int		i;
	int 	ret;
	int 	defined;
	char 	*line;

	defined = 0;
	while ((ret = get_next_line(1, &line)) > 0 && !(defined))
	{
		if (ft_strnstr("$$$ exec:", line, BUFF_SIZE))
		{
			if (ft_strnstr(PLAYER, line, BUFF_SIZE))
			{
				(*(player))->player = 'o';
				(*(player))->opponent = 'x';
			}
			else
			{
				(*(player))->player = 'x';
				(*(player))->opponent = 'o';
			}
			defined = 1;
		}
		ft_strdel(&line);
	}
}

/*
** Inits the player by assigning memort and setting the values
*/

void	init_game(t_map **map, t_piece **piece, t_player **player)
{
	if (!(*map = (t_map*)ft_memalloc(sizeof(t_map))))
		perror("ERROR");
	if (!(*piece = (t_piece*)ft_memalloc(sizeof(t_piece))))
		perror("ERROR");
	if (!(*piece = (t_player*)ft_memalloc(sizeof(t_player))))
		perror("ERROR");
	(*(map))->read = 0;
	(*(map))->layout = NULL;
	(*(piece))->read = 0;
}

/*
** Reads the standard output as long as there is something to read to finds the
** keyword 'fin:' from the result.
*/

int		main(void)
{
	int			ret;
	int 		game_ongoing;
	t_map		*map;
	t_piece		*piece;
	t_player	*player;

	init_game(&map, &piece, &player);
	set_player(&player);
	game_ongoing = 1;
	while (game_ongoing)
	{
		if (!(map->read))
			game_ongoing = read_map(&map);
		else if (!(piece->read))
			game_ongoing = read_piece(&piece);
		else
			game_ongoing = place_piece(&map, &piece, &player);
	}
	//free all maps and strucst
	return (0);
}
