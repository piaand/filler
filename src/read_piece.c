/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:39:09 by pandersi          #+#    #+#             */
/*   Updated: 2020/08/12 17:33:08 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Adds rows to piece layout but makes sure that adding continues only for known
** row amount at piece struct. Returns 1 when layout is finished.
*/

int		build_piece_layout(t_piece **piece)
{
	static int	row_count;
	int 		len;
	int 		ret;
	char		*row;
	char		*row_clean;
	char 		**layout;

	len = (*(piece))->col;
	layout = (*(piece))->layout;
	while(row_count < ((*(piece))->row))
	{
		ret = get_next_line(0, &row);
		row_clean = ft_strsub(row, 0, len);
		layout[row_count] = row_clean;
		write_to_log(row_clean);
		row_count++;
	}
	return (1);
}

/*
** Creates a char array according the x and y coordinates given by the game.
*/

void	init_piece(t_piece **piece, char *str)
{
	int 	*coordinates;
	char	**piece_layout;

	write_to_log("Initing piece");
	if (!(coordinates = (int*)ft_memalloc(sizeof(int) * 2 + 2)))
		perror("ERROR");
	coordinates = return_coordinates(str, coordinates);
	(*(piece))->row = coordinates[0];
	(*(piece))->col = coordinates[1];
	if (!(piece_layout = (char**)ft_memalloc(sizeof(char*) * ((*(piece))->row) + 2)))
		perror("ERROR");
	(*(piece))->layout = piece_layout;
	write_to_log("Piece coordinates");
	write_to_log(ft_itoa((*(piece))->col));
	write_to_log(ft_itoa((*(piece))->row));
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
	ret = get_next_line(0, &line);
	if (!(ft_strncmp(line, "Piece ", 6)))
		init_piece(piece, line);
	else
	{
		ft_strdel(&line);
		perror("ERROR");
	}	
	if (piecer->layout)
		piece_read = build_piece_layout(piece);
	else
		perror("ERROR");
	piecer->read = piece_read;
	write_to_log("Piece is now read!");
	return (1);
}