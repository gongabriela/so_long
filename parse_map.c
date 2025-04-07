/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:53:25 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/04 19:50:39 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *err_msg, char ***map_data)
{
	int	i;

	ft_putendl_fd(err_msg, 2);
	i = 0;
	if (map_data != NULL)
	{
		while ((*map_data)[i] != NULL)
			free((*map_data)[i++]);
		free(*map_data);
	}
	exit(1);
}

void	parse_map_file(int argc, char *file)
{
	if (argc != 2)
		ft_exit("invalid number of arguments", NULL);
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		ft_exit("file is not .ber", NULL);
	if (access(file, R_OK) == -1)
		ft_exit("file not found or permission denied", NULL);
}

void	init_map(char *argv, char ***map_data)
{
	char	*line;
	char	*temp;
	char	*temp_2;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit("open() failed at init map", NULL);
	line = get_next_line(fd);
	if (line == NULL)
		ft_exit("invalid map: map empty", NULL);
	else
		temp = get_next_line(fd);
	while (temp != NULL)
	{
		temp_2 = line;
		line = ft_strjoin(line, temp);
		if (line == NULL)
			ft_exit("malloc() failed in ft_strjoin at init_map()", NULL);
		free(temp_2);
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	*map_data = ft_split(line, '\n');
	free(line);
	if (*map_data == NULL)
		ft_exit("malloc() failed in ft_split() at init_map()", NULL);
}

void	parse_map_size(char	***map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen((*map)[i]);
	i++;
	while ((*map)[i] != NULL)
	{
		if (len != ft_strlen((*map)[i]))
			ft_exit("error: this map is not a rectangle", map);
		i++;
	}
	if (i < 2)
		ft_exit("error: this map is not a rectangle", map);
}

void	check_outer_walls(char ***map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while((*map)[i][j] != '\0' && (*map)[i][j] != '\r')
	{
		if ((*map)[i][j] != '1')
			ft_exit("invalid map", map);
		j++;
	}
	i++;
	while((*map)[i + 1] != NULL)
	{
		if ((*map)[i][0] != '1' || (*map)[i][ft_strlen((*map)[i]) - 2] != '1')
			ft_exit("invalid map", map);
		i++;
	}
	j = 0;
	while((*map)[i][j] != '\0' && (*map)[i][j] != '\r')
	{
		if ((*map)[i][j] != '1')
			ft_exit("invalid map", map);
		j++;
	}
}

int	check_inter(char *t_map, int *collectibles, int *player, int *exit)
{
	size_t	j;

	j = 0;
	while (t_map[j])
	{
		if (t_map[j] == 'C')
		(*collectibles)++;
		else if (t_map[j] == 'P')
			(*player)++;
		else if (t_map[j] == 'E')
			(*exit)++;
		else if (ft_strchr("10CEP\r", t_map[j]) == NULL)
			return (-1);
		j++;
	}
	return (0);
}
void	parse_map_content(char ***map, int *collectibles)
{
	size_t	i;
	int		player;
	int		exit;

	i = 0;
	player = 0;
	exit = 0;
	check_outer_walls(map);
	while ((*map)[i])
	{
		if (check_inter((*map)[i], collectibles, &player, &exit) == -1)
			ft_exit("invalid map", map);
		i++;
	}
	if ((*collectibles) < 1 || player != 1 || exit != 1)
		ft_exit("invalid map", map);
}

void	parse_map_paths(char ***map, int *collectibles)
{
	//fazer uma copia do map
	//encontrar a posicao do p
	//tentar andar para cima, baixo, frente e tras nas pos validas (wque nao sao 1)
	//keep track of pos visitadas
	//ir contando por quantos coletaveis e a saida passam
}

void	parse_map(int argc, char *argv, char ***map)
{
	int	collectibles;

	parse_map_file(argc, argv); //se so ha 2 args, se o file tem .ber, se o file e readable
	init_map(argv, map); //colocar o mapa em um char **
	parse_map_size(map); //se e maior do que deveria, se nao existe, se e um retangulo
	parse_map_content(map, &collectibles); //ver se se o mapa e contornado por paredes, se tem 1 player, 1 exit, e no minimo 1 coletavel. ver se o resto e espaco livre e nao tem uma letra desconhecida
	parse_map_paths(map, &collectibles); //ver se e possivel apanhar todos os coletaveis e chegar a saida com o flood fill algorithm
}
