/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:50:54 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/09 16:48:33 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_image_ptr(t_mlx *mlx)
{
	int width;
	int height;

	mlx->player_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "img/player.xpm", &width, &height);
	mlx->wall_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "img/walls.xpm", &width, &height);
	mlx->col_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "img/collectibles.xpm", &width, &height);
	mlx->exit_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "img/exit.xpm", &width, &height);
	mlx->bg_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "img/background.xpm", &width, &height);

	if (!mlx->player_img || !mlx->wall_img || !mlx->col_img || !mlx->exit_img || !mlx->bg_img)
		return (-1);
	return (0);
}
void	render_background(t_mlx *mlx, t_data *data, char **map)
{
	int	x;
	int	y;

	x = 0;
	while(x < data->h && map[x])
	{
		y = 0;
		while (y < data->w && map[x][y] != '\0')
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->bg_img, (y * TILE_SIZE), (x * TILE_SIZE));
			y++;
		}
		x++;
	}
}

void	render_walls(t_mlx *mlx, char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->wall_img, (y * TILE_SIZE), (x * TILE_SIZE));
			y++;
		}
		x++;
	}
}
void	render_exit(t_mlx *mlx, char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->exit_img, (y * TILE_SIZE), (x * TILE_SIZE));
			y++;
		}
		x++;
	}
}
/*void	render_collectibles(t_mlx mlx, t_data *data)
{

}
void	render_player(t_mlx mlx, t_data *data)
{

}*/
void	load_game(t_data *data)
{
	if (get_image_ptr(&data->mlx) == -1)
		ft_exit("Error: failed to get pointer of .xpm file", data);
	render_background(&data->mlx, data, data->map);
	render_walls(&data->mlx, data->map);
	render_exit(&data->mlx, data->map);
	/*render_collectibles(data->mlx, data);
	render_player(data->mlx, data);*/
}
