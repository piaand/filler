/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:01:53 by pandersi          #+#    #+#             */
/*   Updated: 2020/08/12 16:27:14 by pandersi         ###   ########.fr       */
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

void		buid_map_layout(t_map **map)
{
	int			row_count;
	int 		len;
	int 		ret;
	char		*row;
	char		*row_clean;
	char 		**layout;

	write_to_log("Add a new map layout.");
	row_count = 0;
	layout = (*(map))->layout;
	len = (*(map))->col;
	ret = get_next_line(0, &row);
	write_to_log(row);
	if (!(ft_strlen(row) > (size_t)len))
	{
		ft_strdel(&row);
		perror("ERROR");
	}
	else
	{
		write_to_log("Started to fill rows.");
		while(row_count < (*(map))->row)
		{
			ret = get_next_line(0, &row);
			row_clean = ft_strsub(row, 4, len);
			write_to_log(row_clean);
			layout[row_count] = row_clean;
			ft_strdel(&row);
			ft_strdel(&row_clean);
			row_count++;
		}
	}
}

/*
** Creates a char array according the x and y coordinates given by the game.
*/

void	init_map(t_map **map)
{
	int		ret;
	char	*str;
	int 	*coordinates;
	char	**map_layout;

	write_to_log("Init new map.");
	ret = get_next_line(0, &str);
	write_to_log(str);
	if (ret != -1 && ft_strncmp(str, "Plateau", 7) == 0)
	{
		write_to_log("Valid mapinstructions.");
		if (!(coordinates = (int*)ft_memalloc(sizeof(int) * 2 + 2)))
			perror("ERROR");
		coordinates = return_coordinates(str, coordinates);
		(*(map))->row = coordinates[0];
		(*(map))->col = coordinates[1];
		if (!(map_layout = (char**)ft_memalloc(sizeof(char*) * ((*(map))->row) + 2)))
			perror("ERROR");
		(*(map))->layout = map_layout;
		free(coordinates);
		write_to_log("Coordinates:");
		write_to_log(ft_itoa((*(map))->col));
		write_to_log(ft_itoa((*(map))->row));
		ft_strdel(&str);
	}
	else
	{
		ft_strdel(&str);
		perror("ERROR");
	}
}


/*
** Tries to find the map from standard output. When finds the map dimensions,
** inits the map layout and reads the layout according to the dimensions.
*/

int	read_map(t_map **map)
{
	t_map	*mapper;

	mapper = *map;
	write_to_log("Starts to read map.");
	init_map(map);
	buid_map_layout(map);
	write_to_log("Map is now read.");
	mapper->read = 1;
	return (1);
}
