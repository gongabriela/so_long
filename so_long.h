/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:14:36 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/11 10:22:37 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <X11/keysym.h>
# define TILE_SIZE 32

typedef struct s_pos
{
	int	x;
	int	y;
	int	col;
	int	exit;
}				t_pos;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	void	*player_img;
	void	*wall_img;
	void	*col_img;
	void	*exit_img;
	void	*bg_img;
}			t_mlx;

typedef struct s_data
{
	int		fd;
	char	**map;
	int		h;
	int		w;
	char	**ff_map;
	int		collectibles;
	int		ff_found;
	int		ff_exit;
	int		mov;
	t_pos	pos;
	t_mlx	mlx;

}			t_data;

//init structs
void	init_structs(t_data *data, t_mlx *mlx);

//parsing the .ber map
void	parse_map(int argc, char *argv, t_data *data);
void	parse_map_file(int argc, char *file, t_data *data);
void	init_map(t_data *data);
void	parse_map_size(t_data *data);
void	check_inter(t_data *data, int x, int *exit, int *player);
void	parse_map_content(t_data *data);
void	get_player_position(t_data *data);
void	copy_map_to_ff(t_data *data);
void	flood_fill(char **matrix, t_data *data, int x, int y);

//render map
void	load_game(t_data *data);
int		get_image_ptr(t_mlx *mlx);
void	render_background(t_mlx *mlx, t_data *data, char **map);
void	render_walls(t_mlx *mlx, char **map);
void	render_exit(t_mlx *mlx, char **map);
void	render_collectibles(t_mlx *mlx, char **map);
void	render_player(t_mlx *mlx, char **map);

//hooks
int		key_handler(int key_input, t_data *data);
void	update_map_w(t_data *data, char **map, t_pos *pos);
void	update_map_s(t_data *data, char **map, t_pos *pos);
void	update_map_a(t_data *data, char **map, t_pos *pos);
void	update_map_d(t_data *data, char **map, t_pos *pos);

//free and error/exit functions
int		ft_exit(char *err_msg, t_data *data);
void	ft_free_mlx_img(t_mlx *mlx);
void	ft_free_mlx(t_mlx *mlx);
int		ft_exit_hook(t_data *data);

//testing
void	print_map(char **map);

#endif
