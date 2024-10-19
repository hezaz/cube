/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hedi <hedi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:33:15 by hedi              #+#    #+#             */
/*   Updated: 2024/07/19 15:39:44 by hedi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void handle_floor_ceiling_texture(char *line, t_rgb *texture_rgb, int *is_rgb)
{
    line = skip_spaces(line);
    if (is_rgb_color(line))
    {
        *texture_rgb = parse_rgb(line);
        *is_rgb = 1;
    }
    else
    {
        *is_rgb = 0;
    }
}

void handle_texture_floor(t_map *map, char *line)
{
    handle_floor_ceiling_texture(line, &(map->texture->floor), &(map->texture->floor_is_rgb));
}

void handle_texture_ceiling(t_map *map, char *line)
{
    handle_floor_ceiling_texture(line, &(map->texture->ceiling), &(map->texture->ceiling_is_rgb));
}
