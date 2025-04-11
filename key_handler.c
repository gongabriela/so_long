/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:41:34 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/11 10:18:10 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int key_input, t_data *data)
{
	if (key_input == XK_Escape)
		ft_exit("game over", data);
	if (key_input == XK_w || key_input == XK_Up)
		update_map_w(data, data->map, &data->pos);
	if (key_input == XK_s || key_input == XK_Down)
		update_map_s(data, data->map, &data->pos);
	if (key_input == XK_a || key_input == XK_Left)
		update_map_a(data, data->map, &data->pos);
	if (key_input == XK_d || key_input == XK_Right)
		update_map_d(data, data->map, &data->pos);
	ft_free_mlx_img(&data->mlx);
	load_game(data);
	return (0);
}
