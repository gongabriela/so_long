/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:14:26 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/02 16:06:37 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		perror("Invalid number of arguments");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0 || access(argv[1], R_OK) == -1)
	{
		ft_putendl_fd("invalid file", 2);
		exit(1);
	}
	parse_map(argv[1], &data.map);
	return (0);
}

