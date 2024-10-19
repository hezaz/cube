/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:27:29 by codespace         #+#    #+#             */
/*   Updated: 2024/07/20 11:34:20 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*get_map(char *path)
{
	int		fd;
	int		map_row;
	char	*line;
	t_map	*map;

	map = init_map();
	map->height++;
	get_map_dim(map, path);
	map->map = malloc(sizeof(char *) * map->height);
	if (!map->map)
		ft_error("[get_map(...)] : map->map malloc failed");
	garbage_collector(map->map, false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("[get_map(...)] : opened file returned < 0");
	line = get_next_line(fd);
	map_row = 0;
	while (line)
	{
		if (*line != '\n')
		{
			if (is_texture_line(line))
				get_texture_line(map, line);
			else if (is_map_line(line))
				get_map_line(map, line, &map_row);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}

void	get_map_dim(t_map *map, char *path)
{
	int fd;
	int height;
	char *line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("[get_map_dim(...)] : opened file returned < 0");
	// ft_printf("starting to get dimensions\nstart height = %d\nstart width %d\n",
	// 	map->width, map->height); ////////////////
	height = 0;
	// ft_printf("before loop : height = %d | map->height = %d\n", height,
	// 	map->height); //////////////////////
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n' && is_map_line(line))
		{
			height++;
			// ft_printf("after increment : height = %d | map->height = %d\n",
			// 	height, map->height); //////////////////////
			if ((int)ft_strlen(line) > map->width)
			{
				map->width = ft_strlen(line);
				// ft_printf("new max width = %d\n",
					// map->width); //////////////////////
				// ft_printf("after new max : height = %d | map->height = %d\n",
				// 	height, map->height); //////////////////////
			}
			// ft_printf("end of principal if : height = %d | map->height = %d\n",
			// 	height, map->height); //////////////////////
		}
		free(line);
		line = get_next_line(fd);
		// ft_printf("end of while : height = %d | map->height = %d\n", height,
		// 	map->height); //////////////////////
	}
	free(line);
	// ft_printf("(after free(line)) : height = %d | map->height = %d\n", height,
	// 	map->height); ////////////////////
	map->height = height;
	// ft_printf("final width = %d\nfinal height = %d\n\n", map->width,
	// 	map->height); //////////////////
}