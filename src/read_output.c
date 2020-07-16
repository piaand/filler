/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:01:53 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/16 17:08:01 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	read_map(char *line, t_map **mapper)
{
	t_map *map;

	map = *mapper;
	(void)line;
	map->read = 1;
}

void	read_piece(char *line, t_piece **piecer)
{
	t_piece *piece;

	piece = *piecer;
	(void)line;
	piece->read = 1;
}