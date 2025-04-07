/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:14:26 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/07 15:27:51 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	parse_map(argc, argv[1], &data.map);
	int i = 0;
	while (data.map[i] != NULL)
		ft_printf("%s\n", data.map[i++]);
	i = 0;
	while (data.map[i] != NULL)
		free(data.map[i++]);
	free(data.map);
	return (0);
}

//passar a estrutura em vez de so o mapa
