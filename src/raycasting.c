/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:57:32 by baptistevie       #+#    #+#             */
/*   Updated: 2024/10/24 15:58:49 by hzaz             ###   ########.fr       */
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

t_texture_img	*select_texture(t_game *data, t_ray *ray)
{
	if (ray->side == 0 && ray->ray_dirX > 0)
		return (data->textures[2]);
	else if (ray->side == 0 && ray->ray_dirX < 0)
		return (data->textures[3]);
	else if (ray->side == 1 && ray->ray_dirY > 0)
		return (data->textures[1]);
	else
		return (data->textures[0]);
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

void	draw_line(t_game *data, t_ray *ray, int x)
{
	t_draw_params	params;

	calculate_line_dimensions(ray, &params.line_height, &params.draw_start,
		&params.draw_end);
	params.wallX = calculate_wallx(data, ray);
	params.texture = select_texture(data, ray);
	params.texX = adjust_texture_x(ray, params.texture, params.wallX);
	params.step = 1.0 * params.texture->height / params.line_height;
	params.texPos = (params.draw_start - WINDOW_HEIGHT / 2 + params.line_height
			/ 2) * params.step;
	draw_texture_line(data, ray, x, &params);
}

int	get_texture_color(t_texture_img *texture, int x, int y)
{
	char	*dst;

	dst = texture->data + (y * texture->size_line + x * (texture->bpp / 8));
	return (*(unsigned int *)dst);
}

void	perform_dda(t_game *data, t_ray *ray)
{
	ray->wall_hit = false;
	while (!ray->wall_hit)
	{
		if (ray->side_distX < ray->side_distY)
		{
			ray->side_distX += ray->delta_distX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->side_distY += ray->delta_distY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (data->map->map[ray->mapY][ray->mapX] == '1')
			ray->wall_hit = true;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_distX - ray->delta_distX;
	else
		ray->perp_wall_dist = ray->side_distY - ray->delta_distY;
}

void	get_initial_values(t_game *data, t_ray *ray)
{
	if (ray->ray_dirX < 0)
	{
		ray->stepX = -1;
		ray->side_distX = (data->player->pos->x - ray->mapX) * ray->delta_distX;
	}
	else
	{
		ray->stepX = 1;
		ray->side_distX = (ray->mapX + 1.0 - data->player->pos->x)
			* ray->delta_distX;
	}
	if (ray->ray_dirY < 0)
	{
		ray->stepY = -1;
		ray->side_distY = (data->player->pos->y - ray->mapY) * ray->delta_distY;
	}
	else
	{
		ray->stepY = 1;
		ray->side_distY = (ray->mapY + 1.0 - data->player->pos->y)
			* ray->delta_distY;
	}
}

void	get_position(t_game *data, t_ray *ray)
{
	ray->mapX = (int)(data->player->pos->x);
	ray->mapY = (int)(data->player->pos->y);
	if (ray->ray_dirX == 0)
		ray->delta_distX = 1e30;
	else
		ray->delta_distX = fabs(1 / (ray->ray_dirX));
	if (ray->ray_dirY == 0)
		ray->delta_distY = 1e30;
	else
		ray->delta_distY = fabs(1 / (ray->ray_dirY));
}

void	cast_rays(t_game *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		ray.camX = 2 * x / (double)WINDOW_WIDTH - 1;
		ray.ray_dirX = data->player->dir->x + data->player->plan->x * ray.camX;
		ray.ray_dirY = data->player->dir->y + data->player->plan->y * ray.camX;
		get_position(data, &ray);
		get_initial_values(data, &ray);
		perform_dda(data, &ray);
		draw_line(data, &ray, x);
		x++;
	}
}
