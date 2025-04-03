/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:53:25 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/03 16:21:32 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *err_msg)
{
	ft_putendl_fd(err_msg, 2);
	exit(1);
}

void	parse_map_file(int argc, char *file)
{
	if (argc != 2)
		ft_exit("invalid number of arguments");
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		ft_exit("file is not .ber");
	if (access(file, R_OK) == -1)
		ft_exit("file not found or permission denied");
}

void	init_map(char *argv, char ***map_data)
{
	char	*line;
	char	*temp;
	char	*temp_2;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit("open() failed at init map");
	line = get_next_line(fd);
	if (line != NULL)
		temp = get_next_line(fd);
	while (temp != NULL)
	{
		temp_2 = line;
		line = ft_strjoin(line, temp);
		free(temp_2);
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	*map_data = ft_split(line, '\n');
	free(line);
	if (*map_data == NULL)
		ft_exit("malloc() failed in ft_split() at init_map()");
}

void	parse_map(int argc, char *argv, char ***map)
{
	parse_map_file(argc, argv); //se so ha 2 args, se o file tem .ber, se o file e readable
	init_map(argv, map); //colocar o mapa em um char **
	/*parse_map_size(); //se e maior do que deveria, se nao existe, se e um retangulo
	parse_map_content(); //ver se se o mapa e contornado por paredes, se tem 1 player, 1 exit, e no minimo 1 coletavel. ver se o resto e espaco livre e nao tem uma letra desconhecida
	parse_map_paths(); //ver se e possivel apanhar todos os coletaveis e chegar a saida com o flood fill algorithm*/
}
