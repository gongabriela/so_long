/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:53:25 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/11 10:29:57 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map_file(int argc, char *file, t_data *data)
{
	if (argc != 2)
		ft_exit("invalid number of arguments", NULL);
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		ft_exit("file is not .ber", NULL);
	data->fd = open(file, O_RDONLY);
	if (data->fd == -1)
		ft_exit("open() failed", NULL);
}

void	init_map(t_data *data)
{
	char	*line;
	char	*temp;
	char	*temp_2;

	line = get_next_line(data->fd);
	if (line == NULL)
		ft_exit("invalid map: map empty", NULL);
	temp = get_next_line(data->fd);
	while (temp != NULL)
	{
		temp_2 = line;
		line = ft_strjoin(line, temp);
		if (line == NULL)
			ft_exit("malloc() failed in ft_strjoin at init_map()", NULL);
		free(temp_2);
		free(temp);
		temp = get_next_line(data->fd);
	}
	close(data->fd);
	data->map = ft_split(line, '\n');
	free(line);
	if (data->map == NULL)
		ft_exit("malloc() failed in ft_split() at init_map()", NULL);
}

void	parse_map_size(t_data *data)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(data->map[i]);
	if (len == 0)
		ft_exit("error: empty map", data);
	i++;
	while (data->map[i] != NULL && len == ft_strlen(data->map[i]))
		i++;
	if (i < 2 || data->map[i] != NULL)
		ft_exit("error: this map is not a rectangle", data);
	data->w = len;
	data->h = i;
}

void	parse_map(int argc, char *argv, t_data *data)
{
	data->ff_exit = 0;
	data->map = NULL;
	data->ff_map = NULL;
	parse_map_file(argc, argv, data);
	init_map(data);
	parse_map_size(data);
	parse_map_content(data);
	get_player_position(data);
	copy_map_to_ff(data);
	flood_fill(data->ff_map, data, data->pos.x, data->pos.y);
	if (data->ff_found != data->collectibles)
		ft_exit("Error: this game is not playable", data);
	if (data->ff_exit != 1)
		ft_exit("Error: this game is not playable", data);
}
