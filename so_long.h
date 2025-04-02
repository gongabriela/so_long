/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:14:36 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/04/02 15:59:52 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./mlx/mlx.h"
# include <stdio.h>
typedef struct s_data
{
	char	**map;

}			t_data;

void	parse_map(char *argv, char ***map);

#endif
