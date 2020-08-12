/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:03:02 by pandersi          #+#    #+#             */
/*   Updated: 2020/08/12 15:34:20 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** This is for error handling.
*/

void	write_to_log(char *mssg)
{
	FILE 		*fp;  

	fp = fopen("log.txt", "a");//opening file, a append
   	fprintf(fp, "%s", mssg);
	fprintf(fp, "\n");
	fclose(fp);//closing file  
}

/*
** Gives the player and opponet x or o depending their player number
*/

void	set_player(t_player **player)
{
	int 	ret;
	char 	*line;

	(*(player))->turn = 0;
	ret = get_next_line(0, &line);
	if (ret > 0 && ft_strnstr(line, "$$$ exec", BUFF_SIZE))
	{
		//write_to_log("Setting player.");
		if (ft_strnstr(line, "p1", BUFF_SIZE))
		{
			(*(player))->player = 'o';
			(*(player))->opponent = 'x';
		}
		else if (ft_strnstr(line, "p2", BUFF_SIZE))
		{
			(*(player))->player = 'x';
			(*(player))->opponent = 'o';
		}
		else
			perror("ERROR setting player");
	}
	ft_strdel(&line);
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
	if (!(*player = (t_player*)ft_memalloc(sizeof(t_player))))
		perror("ERROR");
	(*(map))->read = 0;
	(*(map))->layout = NULL;
	(*(piece))->read = 0;
	(*(piece))->layout = NULL;
}

/*
** Reads the standard output as long as there is something to read to finds the
** keyword 'fin:' from the result.
*/

int		main(void)
{
	int 		game_ongoing;
	t_map		*map;
	t_piece		*piece;
	t_player	*player;

	write_to_log("Starting the player.");
	init_game(&map, &piece, &player);
	set_player(&player);
	if (!(map->read) && !(piece->read) && player->player)
	{
		game_ongoing = 1;
		write_to_log("Game starts!");
		while (game_ongoing)
		{
			write_to_log("New round!");
			if (!(map->read))
				game_ongoing = read_map(&map);
			else if (!(piece->read))
				game_ongoing = read_piece(&piece);
			else
				game_ongoing = place_piece(&map, &piece, &player);
		}
	}
	//free all maps and strucst
	return (0);
}
