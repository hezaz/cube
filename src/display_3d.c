/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:12:48 by baptistevie       #+#    #+#             */
/*   Updated: 2024/10/27 10:13:06 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_int(t_rgb rgb)
{
	int	color;

	color = rgb.r;
	color = (color << 8) + rgb.g;
	color = (color << 8) + rgb.b;
	return (color);
}

void	draw_ceiling(t_game *data)
{
	int	i;
	int	j;
	int	color;

	color = rgb_to_int(data->map->texture->ceiling);
	i = 0;
	while (i <= WINDOW_WIDTH)
	{
		j = WINDOW_HEIGHT / 2;
		while (j < WINDOW_HEIGHT)
		{
			img_pix_put(&data->img, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_floor(t_game *data)
{
	int	i;
	int	j;
	int	color;

	color = rgb_to_int(data->map->texture->floor);
	i = 0;
	while (i <= WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT / 2)
		{
			img_pix_put(&data->img, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_background(t_game *data)
{
	draw_ceiling(data);
	draw_floor(data);
}
