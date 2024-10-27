/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:57:32 by baptistevie       #+#    #+#             */
/*   Updated: 2024/10/27 13:30:55 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_game *data, t_ray *ray, int x)
{
	t_draw_params	params;
	int				y;

	calculate_line_dimensions(ray, &params.line_height, &params.draw_start,
		&params.draw_end);
	y = params.draw_start;
	params.wall_x = calculate_wallx(data, ray);
	params.texture = select_texture(data, ray);
	params.tex_x = adjust_texture_x(ray, params.texture, params.wall_x);
	params.step = 1.0 * params.texture->height / params.line_height;
	params.tex_pos = (params.draw_start - WINDOW_HEIGHT / 2
			+ params.line_height / 2) * params.step;
	if (params.texture->rgb)
		while (y <= params.draw_end)
			img_pix_put(&data->img, (WINDOW_WIDTH - x), y++,
				rgb_to_int(*(params.texture->rgb)));
	else
		draw_texture_line(data, ray, x, &params);
}

void	perform_dda(t_game *data, t_ray *ray)
{
	ray->wall_hit = false;
	while (!ray->wall_hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map->map[ray->map_y][ray->map_x] == '1')
			ray->wall_hit = true;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

void	get_initial_values(t_game *data, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player->pos->x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player->pos->x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player->pos->y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player->pos->y)
			* ray->delta_dist_y;
	}
}

void	get_position(t_game *data, t_ray *ray)
{
	ray->map_x = (int)(data->player->pos->x);
	ray->map_y = (int)(data->player->pos->y);
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / (ray->ray_dir_x));
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / (ray->ray_dir_y));
}

void	cast_rays(t_game *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x <= WINDOW_WIDTH)
	{
		ray.cam_x = 2 * x / (double)WINDOW_WIDTH - 1;
		ray.ray_dir_x = data->player->dir->x
			+ data->player->plan->x * ray.cam_x;
		ray.ray_dir_y = data->player->dir->y
			+ data->player->plan->y * ray.cam_x;
		get_position(data, &ray);
		get_initial_values(data, &ray);
		perform_dda(data, &ray);
		draw_line(data, &ray, x);
		x++;
	}
}
