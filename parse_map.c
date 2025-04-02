/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:53:25 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/02 16:31:22 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(char *argv, char ***map)
{
	init_map(); //colocar o mapa em um char **
	parse_map_size(); //se e maior do que deveria, se nao existe, se e um retangulo
	parse_map_content(); //ver se se o mapa e contornado por paredes, se tem 1 player, 1 exit, e no minimo 1 coletavel. ver se o resto e espaco livre e nao tem uma letra desconhecida
	parse_map_paths(); //ver se e possivel apanhar todos os coletaveis e chegar a saida com o flood fill algorithm
}
