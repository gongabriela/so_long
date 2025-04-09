/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:39:42 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/09 14:40:05 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_inter(t_data *data, int x, int *exit, int *player)
{
	int	y;

	y = 0;
	while (data->map[x][y])
	{
		if ((y == 0 || y == data->w - 2) && data->map[x][y] != '1')
			ft_exit("Error: map is not surrounded by walls", data);
		else if (data->map[x][y] == 'C')
			data->collectibles++;
		else if (data->map[x][y] == 'E')
			(*exit)++;
		else if (data->map[x][y] == 'P')
			(*player)++;
		else if (ft_strchr("10CEP\r", data->map[x][y]) == NULL)
			ft_exit("Error: item in map is not acceptable", data);
		y++;
	}
}

void	parse_map_content(t_data *data)
{
	int	x;
	int	y;
	int	exit;
	int	player;

	data->collectibles = 0;
	exit = 0;
	player = 0;
	x = 0;
	while (data->map[x])
	{
		y = 0;
		if (x == 0 || x == (data->h) - 1)
		{
			while (data->map[x][y] && data->map[x][y] == '1')
				y++;
			if (y != data->w - 1)
				ft_exit("Error: map is not surrounded by walls", data);
		}
		else
			check_inter(data, x, &exit, &player);
		x++;
	}
	if (exit != 1 || data->collectibles < 1 || player != 1)
		ft_exit("Error: invalid number of mandatory items", data);
}

void	get_player_position(t_data *data)
{
	data->pos.x = 0;
	while (data->map[data->pos.x])
	{
		data->pos.y = 0;
		while (data->map[data->pos.x][data->pos.y])
		{
			if (data->map[data->pos.x][data->pos.y] == 'P')
				return ;
			data->pos.y++;
		}
		data->pos.x++;
	}
}

void	copy_map_to_ff(t_data *data)
{
	int	i;

	data->ff_map = ft_calloc(data->h + 1, sizeof(char *));
	i = 0;
	while (data->map[i])
	{
		data->ff_map[i] = ft_strdup(data->map[i]);
		i++;
	}
	data->ff_map[i] = NULL;
	data->ff_found = 0;
}

void	flood_fill(char **matrix, int *found, int x, int y)
{
	if (matrix[x][y] == 'C' || matrix[x][y] == 'E'
		|| matrix[x][y] == 'P' || matrix[x][y] == '0')
	{
		if (matrix[x][y] == 'C' || matrix[x][y] == 'E' || matrix[x][y] == 'P')
			(*found)++;
		matrix[x][y] = 'X';
	}
	else
		return ;
	flood_fill(matrix, found, x + 1, y);
	flood_fill(matrix, found, x - 1, y);
	flood_fill(matrix, found, x, y + 1);
	flood_fill(matrix, found, x, y - 1);
}
