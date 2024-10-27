/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:45:03 by baptistevie       #+#    #+#             */
/*   Updated: 2024/10/27 12:26:28 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_game *data, int x, int y)
{
	double	prev_x;
	double	prev_y;

	prev_x = data->player->pos->x;
	prev_y = data->player->pos->y;
	data->player->pos->x += (data->player->dir->x * x - data->player->dir->y * y) * MOVE_SPEED;
	data->player->pos->y += (data->player->dir->y * x + data->player->dir->x * y) * MOVE_SPEED;
	if (data->map->map[(int)(data->player->pos->y)][(int)prev_x] == '1')
		data->player->pos->y = prev_y;
	if (data->map->map[(int)(prev_y)][(int)(data->player->pos->x)] == '1')
		data->player->pos->x = prev_x;
}

void	rotate_player(t_game *data, double angle)
{
	double	prev_x;
	double	prev_y;

	prev_x = data->player->dir->x;
	prev_y = data->player->dir->y;
	data->player->dir->x = (prev_x * cos(angle)) - (prev_y * sin(angle));
	data->player->dir->y = (prev_x * sin(angle)) + (prev_y * cos(angle));
	prev_x = data->player->plan->x;
	prev_y = data->player->plan->y;
	data->player->plan->x = (prev_x * cos(angle)) - (prev_y * sin(angle));
	data->player->plan->y = (prev_x * sin(angle)) + (prev_y * cos(angle));
}

double	deg_to_rad(double angle_in_degrees)
{
	return (angle_in_degrees * M_PI / 180.0);
}
