/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:32:39 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/10 16:58:44 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_mlx *mlx, t_data *data, char **map)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->h && map[x])
	{
		y = 0;
		while (y < data->w && map[x][y] != '\0')
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->bg_img,
				(y * TILE_SIZE), (x * TILE_SIZE));
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
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->wall_img,
					(y * TILE_SIZE), (x * TILE_SIZE));
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
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->exit_img,
					(y * TILE_SIZE), (x * TILE_SIZE));
			y++;
		}
		x++;
	}
}

void	render_collectibles(t_mlx *mlx, char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->col_img,
					(y * TILE_SIZE), (x * TILE_SIZE));
			y++;
		}
		x++;
	}
}

void	render_player(t_mlx *mlx, char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->player_img,
					(y * TILE_SIZE), (x * TILE_SIZE));
			y++;
		}
		x++;
	}
}
