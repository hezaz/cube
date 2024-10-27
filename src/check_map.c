/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:23:23 by hedi              #+#    #+#             */
/*   Updated: 2024/10/27 10:08:26 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
