/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:14:36 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/04 16:40:53 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	char	**map;

}			t_data;

//parsing the .ber map
void	parse_map(int argc, char *argv, char ***map);
void	parse_map_file(int argc, char *file);
void	parse_map_size(char	***map);
void	parse_map_content(char ***map, int *collectibles);
void	check_outer_walls(char ***map);
int		check_inter(char *t_map, int *collectibles, int *player, int *exit);

//free and error/exit functions
void	ft_exit(char *err_msg, char ***map_data);

#endif
