/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:34:34 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/09/30 10:12:36 by baptistevie      ###   ########.fr       */
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
	int i, j;

	// print_map(data->map); ///////////////////////////////////

    for (i = 0; i < data->map->height; i++)
    {
        for (j = 0; j < data->map->width; j++)
        {
            // if ((int)data->player->y == i && (int)data->player->x == j)
            //     draw_tile(j, i, RED_PIXEL, data); // Couleur du joueur
            /*else*/ if (data->map->map[i][j] == '1')
                draw_tile(j, i, BLUE_PIXEL, data);
            else if (data->map->map[i][j] == '0')
                draw_tile(j, i, WHITE_PIXEL, data);
            else
                draw_tile(j, i, BLACK_PIXEL, data);
        }
    }
}

void draw_player(t_game *data)
{
	int	i, j;
	// double	y_intercept;
	// double slope;

	// PLAYER DISPLAY

	i = (int)(data->player->pos->x * 30);
	j = (int)(data->player->pos->y * 30);
	// ft_printf("### PLAYER DATA ###\n\tpix i = %d\n\tpix j = %d\n\tplayer x = %d\n\tplayer y = %d\n\n", i, j,(int)data->player->pos->x, (int)data->player->pos->y); // debug
	for (int m = -3; m <= 3; m++)
	{
		for (int n = -3; n <= 3; n++)
		{
			img_pix_put(&data->img, i + m, j + n, RED_PIXEL);
		}
	}

	// // ORIENTATION

	for (int k = 1; k < 5; k++)
	{
		i = (int)((data->player->pos->x + (k * (data->player->dir->x * MOVE_SPEED))) * 30);
		j = (int)((data->player->pos->y + (k * (data->player->dir->y * MOVE_SPEED))) * 30);
		img_pix_put(&data->img, i, j, BLACK_PIXEL);
	}
	// ft_printf("### DIR DATA ###\n\tangle = %d\n\tpos y = %d\n\tpos x = %d\n\n", (int)(data->player->angle), i, j); // debug

	// slope = get_slope(data->player->angle);
	// y_intercept = data->player->y - (data->player->x * slope);
	
	// ft_printf("### MATHS DATA ###\n\tslope = %d\n\ty_inter = %d\n\n", (int)slope, (int)y_intercept); // debug
	// for (int m = 0; m <= 100; m++)
	// {
	// 	i += m;
	// 	j = (int)(((double)i * slope + (double)y_intercept));
	// 	img_pix_put(&data->img, i, j, RED_PIXEL);
	// }
}