/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:14:26 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/11 10:07:20 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_structs(t_data *data, t_mlx *mlx)
{
	data->map = NULL;
	data->ff_map = NULL;
	mlx->mlx_ptr = NULL;
	mlx->win = NULL;
	mlx->player_img = NULL;
	mlx->wall_img = NULL;
	mlx->col_img = NULL;
	mlx->exit_img = NULL;
	mlx->bg_img = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_structs(&data, &data.mlx);
	parse_map(argc, argv[1], &data);
	data.mlx.mlx_ptr = mlx_init();
	if (!data.mlx.mlx_ptr)
		ft_exit("Error: failed to init mlx library", &data);
	data.w = data.w - 1;
	data.mlx.win = mlx_new_window(data.mlx.mlx_ptr, (data.w * TILE_SIZE),
			(data.h * TILE_SIZE), "map.ber");
	if (!data.mlx.win)
		ft_exit("Error: failed to open game window", &data);
	load_game(&data);
	data.mov = 0;
	mlx_key_hook(data.mlx.win, key_handler, &data);
	mlx_hook(data.mlx.win, 17, 0, ft_exit_hook, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
