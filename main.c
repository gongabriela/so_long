/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:14:26 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/08 16:23:29 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	parse_map(argc, argv[1], &data);
	ft_printf("map:\n");
	print_map(data.map);
	ft_printf("flood_fill matrix:\n");
	print_map(data.ff_map);
	ft_exit("OK!", &data);
	return (0);
}

//passar a estrutura em vez de so o mapa
