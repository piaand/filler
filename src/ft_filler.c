/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:03:02 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/20 12:26:43 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

/*
** Gives the player and opponet x or o depending their player number
*/

void	set_player(char **line, t_player **player)
{	
	int i;
	int ret;
	int defined;

	defined = 0;
	while ((ret = get_next_line(1, line)) > 0 && !(defined))
	{
		if (ft_strnstr("$$$ exec:", *line, BUFF_SIZE))
		{
			if (ft_strnstr(PLAYER, *line, BUFF_SIZE))
			{
				(*(player))->player = 'o';
				(*(player))->opponent = 'x';
				(*(player))->turn = 1;
			}
			else
			{
				(*(player))->player = 'x';
				(*(player))->opponent = 'o';
				(*(player))->turn = 0;
			}
			defined = 1;
		}
	}
}

/*
** Inits the player by assigning memort and setting the values
*/

void	init_player(t_map **map, t_piece **piece, t_player **player)
{
	if (!(*map = (t_map*)ft_memalloc(sizeof(t_map))))
		perror("ERROR");
	if (!(*piece = (t_piece*)ft_memalloc(sizeof(t_piece))))
		perror("ERROR");
	if (!(*piece = (t_player*)ft_memalloc(sizeof(t_player))))
		perror("ERROR");
	(*(map))->read = 0;
	(*(piece))->read = 0;
}

/*
** Reads the standard output as long as there is something to read to finds the
** keyword 'fin:' from the result.
*/

int		main(void)
{
	int			ret;
	char		*str;
	t_map		*map;
	t_piece		*piece;
	t_player	*player;

	init_player(&map, &piece, &player);
	set_player(&str, &player);
	while ((ret = get_next_line(1, &str)) > 0 &&
	!(ft_strnstr("fin:", str, BUFF_SIZE)))
	{
		if (!(map->read))
			read_map(&str, &map);
		else if (!(piece->read))
			read_piece(&str, &piece);
		else
			place_piece(&map, &piece, &player);
	}
	//free all maps and strucst
	return (0);
}
