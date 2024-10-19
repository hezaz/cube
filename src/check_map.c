/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:23:23 by hedi              #+#    #+#             */
/*   Updated: 2024/10/19 18:27:49 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	error_and_exit(char *message, t_game *game)
{
	printf("Error\n%s\n", message);
	garbage_collector(NULL, true,game);
	exit(1);
}

int	is_valid_character(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

void	check_map(t_game *game)
{
	int		y;
	int		x;
	char	**map;
	int		height;
	int		max_width;
	int		line_length;
	int		width;
	int		rightmost_non_space;


	map = game->map->map;
	height = game->map->height;
	max_width = 0;
	// Calculate the maximum width of the map
	for (y = 0; y < height; y++)
	{
		line_length = ft_strlen(map[y]);
		if (line_length > max_width)
			max_width = line_length;
	}
	// Check top border
	for (x = 0; x < max_width; x++)
	{
		if (map[0][x] != '1' && map[0][x] != ' ' && map[0][x] != '\0'
			&& map[0][x] != '\n')
		{
			ft_printf("%c", map[0][x]);
			error_and_exit("Map is not closed at top border", game);
		}
	}
	// Check bottom border
	for (x = 0; x < max_width; x++)
	{
		if (map[height - 1][x] != '1' && map[height - 1][x] != ' ' && map[height
			- 1][x] != '\0' && map[height - 1][x] != '\n')
			error_and_exit("Map is not closed at bottom border",game);
	}
	// Check left and right borders
	for (y = 0; y < height; y++)
	{
		width = ft_strlen(map[y]);
		if (width > 0 && (map[y][0] != '1' && map[y][0] != ' '))
			error_and_exit("Map is not closed at left border", game);
		if (width > 1)
		{
			rightmost_non_space = width - 1;
			while (rightmost_non_space > 0
				&& (map[y][rightmost_non_space] == ' '
					|| map[y][rightmost_non_space] == '\n'))
				rightmost_non_space--;
			if (map[y][rightmost_non_space] != '1')
				error_and_exit("Map is not closed at right border",game);
		}
	}
	// Check inner part of the map
	for (y = 1; y < height - 1; y++)
	{
		for (x = 1; map[y][x] != '\0'; x++)
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ' || map[y][x
					- 1] == ' ' || map[y][x + 1] == ' ' || map[y - 1][x] == '\0'
					|| map[y + 1][x] == '\0' || map[y][x - 1] == '\0'
					|| map[y][x + 1] == '\0')
					error_and_exit("Map is not closed around spaces", game);
			}
		}
	}
	// ft_printf("\nallgood\n");
}
