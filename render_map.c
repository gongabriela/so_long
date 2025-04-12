/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:50:54 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/11 14:22:08 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_image_ptr(t_mlx *mlx)
{
	int	width;
	int	height;

	mlx->player_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/player.xpm",
			&width, &height);
	mlx->wall_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/walls.xpm",
			&width, &height);
	mlx->col_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"textures/collectibles.xpm", &width, &height);
	mlx->exit_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/exit.xpm",
			&width, &height);
	mlx->bg_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/background.xpm",
			&width, &height);
	if (!mlx->player_img || !mlx->wall_img || !mlx->col_img || !mlx->exit_img
		|| !mlx->bg_img)
		return (-1);
	return (0);
}

void	load_game(t_data *data)
{
	if (get_image_ptr(&data->mlx) == -1)
		ft_exit("Error\nFailed to get pointer of .xpm file", data);
	render_background(&data->mlx, data, data->map);
	render_walls(&data->mlx, data->map);
	render_exit(&data->mlx, data->map);
	render_collectibles(&data->mlx, data->map);
	render_player(&data->mlx, data->map);
}
