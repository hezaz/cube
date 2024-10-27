/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:27:23 by baptistevie       #+#    #+#             */
/*   Updated: 2024/10/27 10:11:53 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_direction(char direction, t_player *player)
{
	if (direction == 'N')
		player->dir = init_vector(0.0f, -1.0f);
	else if (direction == 'S')
		player->dir = init_vector(0.0f, 1.0f);
	else if (direction == 'E')
		player->dir = init_vector(1.0f, 0.0f);
	else if (direction == 'W')
		player->dir = init_vector(-1.0f, 0.0f);
}

t_player	*find_player_position(t_map *map, t_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S'
				|| map->map[y][x] == 'E' || map->map[y][x] == 'W')
			{
				player->pos = init_vector((double)x + 0.5f, (double)y + 0.5f);
				set_player_direction(map->map[y][x], player);
				player->plan = init_vector(player->dir->y, -(player->dir->x));
				map->map[y][x] = '0';
				return (player);
			}
			x++;
		}
		y++;
	}
	return (NULL);
}

t_player	*init_player(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		ft_error("[init_player] : player malloc failed");
	garbage_collector(player, false, NULL);
	return (find_player_position(map, player));
}
