/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:39:12 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/11 10:36:07 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_mlx_img(t_mlx *mlx)
{
	if (mlx->bg_img != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->bg_img);
	if (mlx->wall_img != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->wall_img);
	if (mlx->col_img != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->col_img);
	if (mlx->exit_img != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->exit_img);
	if (mlx->player_img != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player_img);
}

void	ft_free_mlx(t_mlx *mlx)
{
	ft_free_mlx_img(mlx);
	if (mlx->mlx_ptr != NULL && mlx->win != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	if (mlx->mlx_ptr != NULL)
		mlx_destroy_display(mlx->mlx_ptr);
	if (mlx->mlx_ptr != NULL)
		free(mlx->mlx_ptr);
}

int	ft_exit(char *err_msg, t_data *data)
{
	int	i;

	if (err_msg != NULL)
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
	if (data != NULL)
		ft_free_mlx(&data->mlx);
	exit(0);
	return (0);
}

int	ft_exit_hook(t_data *data)
{
	ft_exit(NULL, data);
	return (0);
}
