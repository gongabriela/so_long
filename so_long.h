/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:14:36 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/08 16:41:35 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pos
{
	int	x;
	int	y;
	int	col;
	int	exit;
}				t_pos;
typedef struct s_data
{
	int		fd;
	char	**map;
	int		h;
	int		w;
	char	**ff_map;
	int		collectibles;
	int		ff_found;
	t_pos	pos;

}			t_data;

//parsing the .ber map
void	parse_map(int argc, char *argv, t_data *data);
void	parse_map_file(int argc, char *file, t_data *data);
void	init_map(t_data *data);
void	parse_map_size(t_data *data);
void	check_inter(t_data *data, int x, int *exit, int *player);
void	parse_map_content(t_data *data);
void	get_player_position(t_data *data);
void	copy_map_to_ff(t_data *data);
void	flood_fill(char **matrix, int *found, int x, int y);

//free and error/exit functions
void	ft_exit(char *err_msg, t_data *data);

//testing
void	print_map(char **map);

#endif
