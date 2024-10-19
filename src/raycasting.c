/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:57:32 by baptistevie       #+#    #+#             */
/*   Updated: 2024/10/12 18:01:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_game *data)
{
	int	x;
	t_ray	ray;

	// printf("we cast rays\n");
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		ray.camX = 2 * x / (double)WINDOW_WIDTH - 1;
		ray.ray_dirX = data->player->dir->x + data->player->plan->x * ray.camX;
		ray.ray_dirY = data->player->dir->y + data->player->plan->y * ray.camX;
		get_position(data, &ray);
		// printf("on position [%d][%d]\n\n", ray.mapX, ray.mapY);
		get_initial_values(data, &ray);
		perform_dda(data, &ray);
		draw_line(data, &ray, x);
		x++;
	}

}

void	get_position(t_game *data, t_ray *ray)
{
	ray->mapX = (int)(data->player->pos->x);
	ray->mapY = (int)(data->player->pos->y);

	if (ray->ray_dirX == 0)
		ray->delta_distX = 1e30;
	else
		ray->delta_distX = fabs(1/(ray->ray_dirX));
	if (ray->ray_dirY == 0)
		ray->delta_distY = 1e30;
	else
		ray->delta_distY = fabs(1/(ray->ray_dirY));
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
		ray->side_distX = (ray->mapX + 1.0 - data->player->pos->x) * ray->delta_distX;
	}

	if (ray->ray_dirY < 0)
	{
		ray->stepY = -1;
		ray->side_distY = (data->player->pos->y - ray->mapY) * ray->delta_distY;
	}
	else
	{
		ray->stepY = 1;
		ray->side_distY = (ray->mapY + 1.0 - data->player->pos->y) * ray->delta_distY;
	}
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
		// printf("current map pos is [%d][%d]\n", ray->mapX, ray->mapY);
		if (data->map->map[ray->mapY][ray->mapX] == '1') 
        	ray->wall_hit = true;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_distX - ray->delta_distX;
	else
		ray->perp_wall_dist = ray->side_distY - ray->delta_distY;
}

int get_texture_color(t_texture_img *texture, int x, int y)
{
	char *dst;

	dst = texture->data + (y * texture->size_line + x * (texture->bpp / 8));
	return (*(unsigned int*)dst);
}


void	draw_line(t_game *data, t_ray *ray, int x)
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wallX;
	t_texture_img	texture;
	int				texX;
	double			step;
	double			texPos;
	int				y;

	// Calcul de la hauteur de la ligne à dessiner
	line_height = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);

	// Calcul des positions de début et de fin pour dessiner la ligne
	draw_start = (-line_height / 2) + (WINDOW_HEIGHT / 2);
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (line_height / 2) + (WINDOW_HEIGHT / 2);
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;

	// Calcul de la position exacte où le mur a été touché
	if (ray->side == 0)
		wallX = data->player->pos->y + ray->perp_wall_dist * ray->ray_dirY;
	else
		wallX = data->player->pos->x + ray->perp_wall_dist * ray->ray_dirX;
	wallX -= floor(wallX);

	// Sélection de la texture appropriée en fonction du côté touché
	if (ray->side == 0 && ray->ray_dirX > 0)
		texture = data->textures[2]; // Mur Est
	else if (ray->side == 0 && ray->ray_dirX < 0)
		texture = data->textures[3]; // Mur Ouest
	else if (ray->side == 1 && ray->ray_dirY > 0)
		texture = data->textures[1]; // Mur Sud
	else
		texture = data->textures[0]; // Mur Nord

	// Calcul de la coordonnée X sur la texture
	texX = (int)(wallX * (double)(texture.width));
	if ((ray->side == 0 && ray->ray_dirX > 0) || (ray->side == 1 && ray->ray_dirY < 0))
		texX = texture.width - texX - 1;

	// Calcul du pas pour incrémenter la coordonnée de texture par pixel d'écran
	step = 1.0 * texture.height / line_height;
	// Coordonnée de texture de départ
	texPos = (draw_start - WINDOW_HEIGHT / 2 + line_height / 2) * step;

	y = draw_start;
	while (y <= draw_end)
	{
		int texY = (int)texPos & (texture.height - 1);
		texPos += step;
		int color = get_texture_color(&texture, texX, texY);
		if (ray->side == 1)
			color = (color >> 1) & 0x7F7F7F; // Assombrir les murs Nord/Sud
		img_pix_put(&data->img, (WINDOW_WIDTH - x), y, color);
		y++;
	}
}
