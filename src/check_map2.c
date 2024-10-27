/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:20:05 by baptistevie       #+#    #+#             */
/*   Updated: 2024/10/27 14:45:21 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_inner_part(char **map, int height, t_game *game)
{
	int	y;
	int	x;

	y = 1;
	while (y < height - 1)
	{
		x = 1;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ' || map[y][x
					- 1] == ' ' || map[y][x + 1] == ' ' || map[y - 1][x] == '\0'
					|| map[y + 1][x] == '\0' || map[y][x - 1] == '\0'
					|| map[y][x + 1] == '\0')
					error_and_exit("Map is not closed around spaces", game);
			}
			x++;
		}
		y++;
	}
}

void	check_map(t_game *game)
{
	char	**map;
	int		height;
	int		max_width;

	map = game->map->map;
	height = game->map->height;
	max_width = calculate_max_width(map, height);
	check_top_border(map, max_width, game);
	check_bottom_border(map, height, max_width, game);
	check_left_right_borders(map, height, game);
	check_inner_part(map, height, game);
}
