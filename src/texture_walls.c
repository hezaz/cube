/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:31:05 by hedi              #+#    #+#             */
/*   Updated: 2024/10/12 19:46:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void handle_wall_texture(char *line, char **texture_path, t_rgb *texture_rgb, int *is_xpm)
{
    line = skip_spaces(line);
    if (is_rgb_color(line))
    {
        *texture_path = NULL;
        *is_xpm = 0;
        *texture_rgb = parse_rgb(line);
    }
    else
    {
        *texture_path = ft_strndup(line, ft_strlen(line)-1);
        *is_xpm = 1;
    }
}

void handle_texture_north(t_map *map, char *line)
{
    handle_wall_texture(line, &(map->texture->north_wall), &(map->texture->north_wall_rgb), &(map->texture->north_wall_is_xpm));
}

void handle_texture_south(t_map *map, char *line)
{
    handle_wall_texture(line, &(map->texture->south_wall), &(map->texture->south_wall_rgb), &(map->texture->south_wall_is_xpm));
}

void handle_texture_east(t_map *map, char *line)
{
    handle_wall_texture(line, &(map->texture->east_wall), &(map->texture->east_wall_rgb), &(map->texture->east_wall_is_xpm));
}

void handle_texture_west(t_map *map, char *line)
{
    handle_wall_texture(line, &(map->texture->west_wall), &(map->texture->west_wall_rgb), &(map->texture->west_wall_is_xpm));
}
