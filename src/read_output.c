/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:01:53 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/16 17:36:23 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	read_map(char *line, t_map **map)
{
	t_map *mapper;

	mapper = *map;
	(void)line;
	mapper->read = 1;
}

void	read_piece(char *line, t_piece **piece)
{
	t_piece *piecer;

	piecer = *piece;
	(void)line;
	piecer->read = 1;
}