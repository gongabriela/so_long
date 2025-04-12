/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:53:25 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/12 14:07:00 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map_file(int argc, char *file, t_data *data)
{
	if (argc != 2)
		ft_exit("Error\ninvalid number of arguments", NULL);
	if (ft_strlen(file) <= 9 || ft_strncmp(file + ft_strlen(file) - 4,
			".ber", 4) != 0)
		ft_exit("Error\nfile is not valid", NULL);
	data->fd = open(file, O_RDONLY);
	if (data->fd == -1)
		ft_exit("Error\nopen() failed", NULL);
}

void	check_newline(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] == '\n' && line[i + 1] == '\n') || (line[i] == '\n'
				&& line[i + 1] == '\0'))
		{
			free(line);
			ft_exit("Error\nEmpty lines on map", data);
		}
		i++;
	}
}

void	init_map(t_data *data)
{
	char	*line;
	char	*temp;
	char	*temp_2;

	line = get_next_line(data->fd);
	if (line == NULL)
		ft_exit("Error\ninvalid map: map empty", NULL);
	temp = get_next_line(data->fd);
	while (temp != NULL)
	{
		temp_2 = line;
		line = ft_strjoin(line, temp);
		if (line == NULL)
			ft_exit("Error\nmalloc() failed in ft_strjoin at init_map()", NULL);
		free(temp_2);
		free(temp);
		temp = get_next_line(data->fd);
	}
	close(data->fd);
	check_newline(data, line);
	data->map = ft_split(line, '\n');
	free(line);
	if (data->map == NULL)
		ft_exit("Error\nmalloc() failed in ft_split() at init_map()", NULL);
}

void	parse_map_size(t_data *data)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(data->map[i]);
	if (len == 0)
		ft_exit("Error\nEmpty map", data);
	i++;
	while (data->map[i] != NULL && len == ft_strlen(data->map[i]))
		i++;
	if (i < 2 || data->map[i] != NULL)
		ft_exit("Error\nThis map is not a rectangle", data);
	data->w = len;
	data->h = i;
}

void	parse_map(int argc, char *argv, t_data *data)
{
	data->ff_exit = 0;
	parse_map_file(argc, argv, data);
	init_map(data);
	parse_map_size(data);
	parse_map_content(data);
	get_player_position(data);
	copy_map_to_ff(data);
	flood_fill(data->ff_map, data, data->pos.x, data->pos.y);
	if (data->ff_found != data->collectibles)
		ft_exit("Error\nThis game is not playable", data);
	if (data->ff_exit != 1)
		ft_exit("Error\nThis game is not playable", data);
}
