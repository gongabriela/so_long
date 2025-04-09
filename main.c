/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:14:26 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/09 16:47:00 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	parse_map(argc, argv[1], &data);
	data.mlx.mlx_ptr = mlx_init();
	if (!data.mlx.mlx_ptr)
		ft_exit("Error: failed to init mlx library", &data);
	data.w = data.w - 1;
	data.mlx.win = mlx_new_window(data.mlx.mlx_ptr, (data.w * TILE_SIZE), (data.h * TILE_SIZE), "map.ber");
	if (!data.mlx.win)
		ft_exit("Error: failed to open game window", &data);
	load_game(&data);
	mlx_loop(data.mlx.mlx_ptr);
	ft_exit("OK!", &data);
	return (0);
}


