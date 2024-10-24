/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:23:23 by hedi              #+#    #+#             */
/*   Updated: 2024/10/24 12:02:03 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	error_and_exit(char *message, t_game *game)
{
	printf("Error\n%s\n", message);
	garbage_collector(NULL, true, game);
	exit(1);
}

int	is_valid_character(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

int	calculate_max_width(char **map, int height)
{
	int	y;
	int	line_length;
	int	max_width;

	y = 0;
	max_width = 0;
	while (y < height)
	{
		line_length = ft_strlen(map[y]);
		if (line_length > max_width)
			max_width = line_length;
		y++;
	}
	return (max_width);
}

void	check_top_border(char **map, int max_width, t_game *game)
{
	int	x;

	x = 0;
	while (x < max_width)
	{
		if (map[0][x] != '1' && map[0][x] != ' ' && map[0][x] != '\0'
			&& map[0][x] != '\n')
			error_and_exit("Map is not closed at top border", game);
		x++;
	}
}

void	check_bottom_border(char **map, int height, int max_width, t_game *game)
{
	int	x;

	x = 0;
	while (x < max_width)
	{
		if (map[height - 1][x] != '1' && map[height - 1][x] != ' ' && map[height
			- 1][x] != '\0' && map[height - 1][x] != '\n')
			error_and_exit("Map is not closed at bottom border", game);
		x++;
	}
}

void	check_left_right_borders(char **map, int height, t_game *game)
{
	int	y;
	int	width;
	int	rightmost_non_space;

	y = 0;
	while (y < height)
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
				error_and_exit("Map is not closed at right border", game);
		}
		y++;
	}
}

void	check_inner_part(char **map, int height, t_game *game)
{
	int	y;
	int	x;

	y = 1;
	while (y < height - 1)
	{
		x = 1;
		while (map[y][x] != '\0')
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
			x++;
		}
		y++;
	}
}

void	check_map(t_game *game)
{
	char	**map;
	int		height;
	int		max_width;

	map = game->map->map;
	height = game->map->height;
	max_width = calculate_max_width(map, height);
	check_top_border(map, max_width, game);
	check_bottom_border(map, height, max_width, game);
	check_left_right_borders(map, height, game);
	check_inner_part(map, height, game);
}
