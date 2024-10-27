/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:58:07 by baptistevie       #+#    #+#             */
/*   Updated: 2024/10/27 10:08:38 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_line_dimensions(t_ray *ray, int *line_height, int *draw_start,
		int *draw_end)
{
	*line_height = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);
	*draw_start = -(*line_height) / 2 + WINDOW_HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = *line_height / 2 + WINDOW_HEIGHT / 2;
	if (*draw_end >= WINDOW_HEIGHT)
		*draw_end = WINDOW_HEIGHT - 1;
}

double	calculate_wallx(t_game *data, t_ray *ray)
{
	double	wallx;

	if (ray->side == 0)
		wallx = data->player->pos->y + ray->perp_wall_dist * ray->ray_dirY;
	else
		wallx = data->player->pos->x + ray->perp_wall_dist * ray->ray_dirX;
	return (wallx - floor(wallx));
}

int	adjust_texture_x(t_ray *ray, t_texture_img *texture, double wallX)
{
	int	text;

	text = (int)(wallX * (double)(texture->width));
	if ((ray->side == 0 && ray->ray_dirX > 0) || (ray->side == 1
			&& ray->ray_dirY < 0))
		text = texture->width - text - 1;
	return (text);
}

void	draw_texture_line(t_game *data, t_ray *ray, int x,
		t_draw_params *params)
{
	int	y;
	int	texy;
	int	color;

	y = params->draw_start;
	while (y <= params->draw_end)
	{
		texy = (int)params->texPos & (params->texture->height - 1);
		params->texPos += params->step;
		color = get_texture_color(params->texture, params->texX, texy);
		if (ray->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		img_pix_put(&data->img, (WINDOW_WIDTH - x), y, color);
		y++;
	}
}
