/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 11:52:23 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/22 12:29:42 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# define PLAYER "pandersi.filler"
# define MAPMARKS ".xXoO"

typedef struct		s_player
{
	char			player;
	char			opponent;
}					t_player;

typedef struct		s_map
{
	int				col;
	int				row;
	char			**layout;
	int				read;
}					t_map;

typedef struct		s_piece
{
	int				col;
	int				row;
	char			**layout;
	int				read;
}					t_piece;

int		place_piece(t_map **map, t_piece **piece, t_player **player);
int		read_map(t_map **map);
int		read_piece(t_piece **piece);

#endif