/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:26:29 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/10 15:00:53 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_map_w(t_data *data, char **map, t_pos *pos)
{
	if (map[pos->x - 1][pos->y] == '1')
		return ;
	if (map[pos->x - 1][pos->y] == 'E' && data->collectibles != 0)
		return ;
	if (map[pos->x - 1][pos->y] == 'E' && data->collectibles == 0)
		ft_exit("WIN!", data);
	map[pos->x][pos->y] = '0';
	pos->x = pos->x - 1;
	if (map[pos->x][pos->y] == 'C')
		(data->collectibles)--;
	map[pos->x][pos->y] = 'P';
	data->mov = data->mov + 1;
	ft_printf("movements: %d\n", data->mov);
}

void	update_map_s(t_data *data, char **map, t_pos *pos)
{
	if (map[pos->x + 1][pos->y] == '1')
		return ;
	if (map[pos->x + 1][pos->y] == 'E' && data->collectibles != 0)
		return ;
	if (map[pos->x + 1][pos->y] == 'E' && data->collectibles == 0)
		ft_exit("WIN!", data);
	map[pos->x][pos->y] = '0';
	pos->x = pos->x + 1;
	if (map[pos->x][pos->y] == 'C')
		(data->collectibles)--;
	map[pos->x][pos->y] = 'P';
	data->mov = data->mov + 1;
	ft_printf("movements: %d\n", data->mov);
}

void	update_map_a(t_data *data, char **map, t_pos *pos)
{
	if (map[pos->x][pos->y - 1] == '1')
		return ;
	if (map[pos->x][pos->y - 1] == 'E' && data->collectibles != 0)
		return ;
	if (map[pos->x][pos->y - 1] == 'E' && data->collectibles == 0)
		ft_exit("WIN!", data);
	map[pos->x][pos->y] = '0';
	pos->y = pos->y - 1;
	if (map[pos->x][pos->y] == 'C')
		(data->collectibles)--;
	map[pos->x][pos->y] = 'P';
	data->mov = data->mov + 1;
	ft_printf("movements: %d\n", data->mov);
}

void	update_map_d(t_data *data, char **map, t_pos *pos)
{
	if (map[pos->x][pos->y + 1] == '1')
		return ;
	if (map[pos->x][pos->y + 1] == 'E' && data->collectibles != 0)
		return ;
	if (map[pos->x][pos->y + 1] == 'E' && data->collectibles == 0)
		ft_exit("WIN!", data);
	map[pos->x][pos->y] = '0';
	pos->y = pos->y + 1;
	if (map[pos->x][pos->y] == 'C')
		(data->collectibles)--;
	map[pos->x][pos->y] = 'P';
	data->mov = data->mov + 1;
	ft_printf("movements: %d\n", data->mov);
}
