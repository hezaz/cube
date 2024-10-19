/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:33:15 by hedi              #+#    #+#             */
/*   Updated: 2024/10/19 18:19:53 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_floor_ceiling_texture(char *line, t_rgb *rgb, int *is_rgb)
{
	line = skip_spaces(line);
	if (is_rgb_color(line))
	{
		*rgb = parse_rgb(line);
		*is_rgb = 1;
	}
	else
		*is_rgb = 0;
}

void	handle_texture_floor(t_map *map, char *line)
{
	handle_floor_ceiling_texture(line, &(map->texture->floor),
		&(map->texture->floor_is_rgb));
}

void	handle_texture_ceiling(t_map *map, char *line)
{
	handle_floor_ceiling_texture(line, &(map->texture->ceiling),
		&(map->texture->ceiling_is_rgb));
}
