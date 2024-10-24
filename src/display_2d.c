/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:34:34 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/10/24 12:12:23 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_tile(int x, int y, int color, t_game *data)
{
	int	tile_width;
	int	tile_height;
	int	i;
	int	j;

	tile_width = 30;
	tile_height = 30;
	i = x * tile_width;
	while (i < tile_width * (x + 1))
	{
		j = y * tile_height;
		while (j < tile_height * (y + 1))
		{
			if (i + 1 == tile_width * (x + 1) || j + 1 == tile_height * (y + 1))
				img_pix_put(&data->img, i, j, BLACK_PIXEL);
			else
				img_pix_put(&data->img, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (data->map->map[i][j] == '1')
				draw_tile(j, i, BLUE_PIXEL, data);
			else if (data->map->map[i][j] == '0')
				draw_tile(j, i, WHITE_PIXEL, data);
			else
				draw_tile(j, i, BLACK_PIXEL, data);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *data)
{
	int	i;
	int	j;
	int	m;
	int	n;
	int	k;

	i = (int)(data->player->pos->x * 30);
	j = (int)(data->player->pos->y * 30);
	m = -4;
	while (++m <= 3)
	{
		n = -4;
		while (++n <= 3)
			img_pix_put(&data->img, i + m, j + n, RED_PIXEL);
	}
	k = 1;
	while (k < 5)
	{
		i = (int)((data->player->pos->x + (k * (data->player->dir->x
							* MOVE_SPEED))) * 30);
		j = (int)((data->player->pos->y + (k * (data->player->dir->y
							* MOVE_SPEED))) * 30);
		img_pix_put(&data->img, i, j, BLACK_PIXEL);
		k++;
	}
}
