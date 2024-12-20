/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:33:15 by hedi              #+#    #+#             */
/*   Updated: 2024/11/11 16:22:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	handle_floor_ceiling_texture(char *line, t_rgb *rgb, int *is_rgb)
{
	line = skip_spaces(line);
	if (is_rgb_color(line))
	{
		*rgb = parse_rgb(line);
		*is_rgb = 1;
		if (!is_valid_rgb(rgb))
			return (false);
	}
	else
		return (false);
	return (true);
}

bool	handle_texture_floor(t_map *map, char *line)
{
	if (map->texture->floor_is_rgb != -1)
		return (false);
	return (handle_floor_ceiling_texture(line, &(map->texture->floor),
			&(map->texture->floor_is_rgb)));
}

bool	handle_texture_ceiling(t_map *map, char *line)
{
	if (map->texture->ceiling_is_rgb != -1)
		return (false);
	return (handle_floor_ceiling_texture(line, &(map->texture->ceiling),
			&(map->texture->ceiling_is_rgb)));
}
