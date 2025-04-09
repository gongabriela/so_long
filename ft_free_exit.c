/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:39:12 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/09 14:45:01 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_mlx(t_mlx mlx)
{
	if (mlx.mlx_ptr != NULL)
		free(mlx.mlx_ptr);
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
	ft_free_mlx(data->mlx);
	if (ft_strncmp(err_msg, "OK!", 3) == 0)
		exit(0);
	exit(1);
}
