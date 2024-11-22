/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:31:05 by hedi              #+#    #+#             */
/*   Updated: 2024/11/22 14:27:16 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	handle_wall_texture(char *line, char **path, int *is_xpm)
{
	line = skip_spaces(line);
	*path = ft_strndup(line, ft_strlen(line) - 1);
	*is_xpm = 1;
	return (is_valid_xpm(*path));
}

bool	handle_texture_north(t_map *map, char *line)
{
	if (map->texture->north_wall)
		return (false);
	return (handle_wall_texture(line, &(map->texture->north_wall),
			&(map->texture->north_wall_is_xpm)));
}

bool	handle_texture_south(t_map *map, char *line)
{
	if (map->texture->south_wall)
		return (false);
	return (handle_wall_texture(line, &(map->texture->south_wall), &(map->texture->south_wall_is_xpm)));
}

bool	handle_texture_east(t_map *map, char *line)
{
	if (map->texture->east_wall)
		return (false);
	return (handle_wall_texture(line, &(map->texture->east_wall), &(map->texture->east_wall_is_xpm)));
}

bool	handle_texture_west(t_map *map, char *line)
{
	if (map->texture->west_wall)
		return (false);
	return (handle_wall_texture(line, &(map->texture->west_wall), &(map->texture->west_wall_is_xpm)));
}
