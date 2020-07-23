/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:39:09 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/23 14:00:53 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Adds rows to piece layout but makes sure that adding continues only for known
** row amount at piece struct. Returns 1 when layout is finished.
*/

int		build_piece_layout(t_piece **piece, char *str)
{
	static int	row_count;
	int 		len;
	char		*row;
	char 		**layout;

	len = (*(piece))->col;
	row = ft_strsub(str, 0, len);
	layout = (*(piece))->layout;
	if (row_count < ((*(piece))->row))
	{
		layout[row_count] = row;
		row_count++;
		return (0);
	}
	else
	{
		row_count = 0;
		return (1);
	}
}

/*
** Creates a char array according the x and y coordinates given by the game.
*/

void	init_piece(t_piece **piece, char *str)
{
	int 	*coordinates;
	char	**piece_layout;

	if (!(coordinates = (int*)ft_memalloc(sizeof(int) * 2 + 2)))
		perror("ERROR");
	coordinates = return_coordinates(str, coordinates);
	(*(piece))->col = coordinates[0];
	(*(piece))->row = coordinates[1];
	if (!(piece_layout = (char**)ft_memalloc(sizeof(char*) * ((*(piece))->row) + 2)))
		perror("ERROR");
	(*(piece))->layout = piece_layout;
	free(coordinates);
}

/*
** Tries to find the piece from standard output. When finds the piece
** dimensions, inits the piece layout and reads the layout according
** to the dimensions.
*/

int	read_piece(t_piece **piece)
{
	int		ret;
	int		piece_read;
	char	*line;
	t_piece	*piecer;

	piecer = *piece;
	piece_read = 0;
	write_to_log("Starts to read piece.");
	while((ret = get_next_line(0, &line) > 0) && !(piece_read)) 
	{
		if (ft_strncmp(line, "Piece ", 6))
			init_piece(piece, line);
		else if (piecer->layout)
			piece_read = build_piece_layout(piece, line);
	}
	piecer->read = piece_read;
	return (1);
}