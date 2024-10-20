/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:25:48 by codespace         #+#    #+#             */
/*   Updated: 2024/10/20 13:22:27 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_texture_line(char *line)
{
	return (ft_strnstr(line, "NO", 2) || ft_strnstr(line, "SO", 2)
		|| ft_strnstr(line, "EA", 2) || ft_strnstr(line, "WE", 2)
		|| ft_strnstr(line, "F", 1) || ft_strnstr(line, "C", 1));
}

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != ' ' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E'
			&& line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

void get_texture_line(t_map *map, char *line)
{
    line = skip_spaces(line);

    if (ft_strnstr(line, "NO", 2))
        handle_texture_north(map, skip_spaces(line + 2));
    else if (ft_strnstr(line, "SO", 2))
        handle_texture_south(map, skip_spaces(line + 2));
    else if (ft_strnstr(line, "EA", 2))
        handle_texture_east(map, skip_spaces(line + 2));
    else if (ft_strnstr(line, "WE", 2))
        handle_texture_west(map, skip_spaces(line + 2));
    else if (ft_strnstr(line, "F", 1))
        handle_texture_floor(map, skip_spaces(line + 1));
    else if (ft_strnstr(line, "C", 1))
        handle_texture_ceiling(map, skip_spaces(line + 1));
}


void	get_map_line(t_map *map, char *line, int *row)
{
	int i;

	map->map[*row] = malloc((map->width + 1) * sizeof(char));
	if (!map->map[*row])
		ft_error("[get_map_line(...)] : malloc failed");
	garbage_collector(map->map[*row], false,NULL);

	i = 0;
	while (line[i] && i < map->width)
	{
		map->map[*row][i] = line[i];
		i++;
	}
	// Remplir les positions restantes avec des espaces
	while (i < map->width)
	{
		map->map[*row][i] = ' ';
		i++;
	}
	map->map[*row][i] = '\0';
	(*row)++;
}
