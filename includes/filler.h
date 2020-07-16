/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 11:52:23 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/16 17:36:38 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct		s_map
{
	int				col;
	int				row;
	char			*map;
	int				read;
	char			player;
	char			opponent;
}					t_map;

typedef struct		s_piece
{
	int				col;
	int				row;
	char			*piece;
	int				read;
}					t_piece;

void	place_piece(t_map **map, t_piece **piece);
void	read_piece(char *line, t_piece **piece);
void	read_map(char *line, t_map **map);

#endif