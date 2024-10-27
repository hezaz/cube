/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:31:05 by hedi              #+#    #+#             */
/*   Updated: 2024/10/27 15:55:28 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	handle_wall_texture(char *line, char **path, t_rgb *rgb, int *is_xpm)
{
	line = skip_spaces(line);
	if (is_rgb_color(line))
	{
		*path = NULL;
		*is_xpm = 0;
		*rgb = parse_rgb(line);
		return (is_valid_rgb(rgb));
	}
	else
	{
		*path = ft_strndup(line, ft_strlen(line) - 1);
		*is_xpm = 1;
		return (is_valid_xpm(*path));
	}
}

bool	handle_texture_north(t_map *map, char *line)
{
	return (handle_wall_texture(line, &(map->texture->north_wall),
			&(map->texture->north_wall_rgb),
			&(map->texture->north_wall_is_xpm)));
}

bool	handle_texture_south(t_map *map, char *line)
{
	return (handle_wall_texture(line, &(map->texture->south_wall),
			&(map->texture->south_wall_rgb),
			&(map->texture->south_wall_is_xpm)));
}

bool	handle_texture_east(t_map *map, char *line)
{
	return (handle_wall_texture(line, &(map->texture->east_wall),
			&(map->texture->east_wall_rgb),
			&(map->texture->east_wall_is_xpm)));
}

bool	handle_texture_west(t_map *map, char *line)
{
	return (handle_wall_texture(line, &(map->texture->west_wall),
			&(map->texture->west_wall_rgb),
			&(map->texture->west_wall_is_xpm)));
}
