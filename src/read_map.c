/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:01:53 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/22 15:05:13 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Writes the coordinates to int array from instuction line ex. "Plateau 10 12"
** or "Piece 3 4"
*/

int *return_coordinates(char *str, int *result)
{
	int		coordinate;
	int		start;
	int		end;
	char	*num;

	coordinate = 0;
	start = 0;
	while(str[start] != '\0')
	{
		while (!(ft_isdigit(str[start])) && str[start] != '\0')
			start++;
		end = start;
		while (ft_isdigit(str[end]) && str[end] != '\0')
			end++;
		if (!(num = ft_strsub(str, start, (end - start))))
			perror("ERROR");
		result[coordinate] = ft_atoi(num);
		coordinate++;
		start = end;
	}
	return (result);
}

/*
** Adds rows to map layout but makes sure that adding continues only for known
** row amount at map struct. Returns 1 when layout is finished.
*/

int		buid_map_layout(t_map **map, char *str)
{
	static int	row_count;
	int 		len;
	char		*row;
	char 		**layout;

	len = (*(map))->col;
	row = ft_strsub(str, 4, len);
	layout = (*(map))->layout;
	if (row_count < ((*(map))->row))
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

void	init_map(t_map **map, char *str)
{
	int 	*coordinates;
	char	**map_layout;

	if (!(coordinates = (int*)ft_memalloc(sizeof(int) * 2 + 2)))
		perror("ERROR");
	coordinates = return_coordinates(str, coordinates);
	(*(map))->col = coordinates[0];
	(*(map))->row = coordinates[1];
	if (!(map_layout = (char**)ft_memalloc(sizeof(char*) * ((*(map))->row) + 2)))
		perror("ERROR");
	(*(map))->layout = map_layout;
	free(coordinates);
}


/*
** Tries to find the map from standard output. When finds the map dimensions,
** inits the map layout and reads the layout according to the dimensions.
*/

int	read_map(t_map **map)
{
	int		ret;
	int		map_read;
	char	*line;
	t_map	*mapper;

	mapper = *map;
	map_read = 0;
	while((ret = get_next_line(1, &line) > 0) && !(map_read)) 
	{
		if (ft_strncmp(line, "Plateau ", 8))
			init_map(map, line);
		else if (mapper->layout)
			map_read = buid_map_layout(map, line);
	}
	mapper->read = map_read;
	return (1);
}
