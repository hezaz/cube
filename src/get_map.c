/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:27:29 by codespace         #+#    #+#             */
/*   Updated: 2024/10/27 15:20:37 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_map(t_map *map, char *path)
{
	map->height++;
	get_map_dim(map, path);
	map->map = malloc(sizeof(char *) * map->height);
	if (!map->map)
		ft_error("[initialize_map] : map->map malloc failed");
	garbage_collector(map->map, false, NULL);
}

void	process_map_file(int fd, t_map *map)
{
	char	*line;
	int		cpt;
	int		map_row;

	line = get_next_line(fd);
	map_row = 0;
	cpt = 0;
	while (line)
	{
		if (*line != '\n')
			process_line(line, &cpt, map, &map_row);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
}

void	process_line(char *line, int *cpt, t_map *map, int *row)
{
	(*cpt)++;
	if (is_texture_line(line))
	{
		if (!get_texture_line(map, line))
			map->map_error = 1;
	}
	else if (!is_map_line(line) && *cpt < 7)
		map->map_error = 1;
	else if (is_map_line(line) && *cpt >= 7)
		get_map_line(map, line, row);
	else
		map->map_error = 1;
}

t_map	*get_map(char *path)
{
	int		fd;
	t_map	*map;

	map = init_map();
	initialize_map(map, path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("[get_map] : failed to open file");
	process_map_file(fd, map);
	return (map);
}

void	get_map_dim(t_map *map, char *path)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("[get_map_dim(...)] : opened file returned < 0");
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n' && is_map_line(line))
		{
			height++;
			if ((int)ft_strlen(line) > map->width)
				map->width = ft_strlen(line);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	map->height = height;
}
