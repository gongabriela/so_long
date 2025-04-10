/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:39:12 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/10 16:51:48 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_mlx_img(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->bg_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->col_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->exit_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->player_img);
}

void	ft_exit(char *err_msg, t_data *data)
{
	int	i;

	ft_putendl_fd(err_msg, 2);
	if (data != NULL)
	{
		if (data->map != NULL)
		{
			i = 0;
			while (data->map[i] != NULL)
				free(data->map[i++]);
			free(data->map);
		}
		if (data->ff_map != NULL)
		{
			i = 0;
			while (data->ff_map[i] != NULL)
				free(data->ff_map[i++]);
			free(data->ff_map);
		}
	}
	ft_free_mlx_img(&data->mlx);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx_ptr);
	if (data->mlx.mlx_ptr != NULL)
		free(data->mlx.mlx_ptr);
	exit(0);
}
