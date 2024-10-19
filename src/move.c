/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:45:03 by baptistevie       #+#    #+#             */
/*   Updated: 2024/09/30 11:46:31 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    move_player(t_game *data, int x) // x should be 1 to move forward or -1 to move backward
{
    double  prev_x;
    double  prev_y;

    prev_x = data->player->pos->x;
    prev_y = data->player->pos->y;
    data->player->pos->x += data->player->dir->x * x * MOVE_SPEED;
    data->player->pos->y += data->player->dir->y * x * MOVE_SPEED;
    printf("prev (x,y) = (%f,%f)\ncurr (x,y) = (%f,%f)\n\n", prev_x, prev_y, data->player->pos->x, data->player->pos->y); // debug
    if (data->map->map[(int)(data->player->pos->y)][(int)prev_x] == '1')
        data->player->pos->y = prev_y;
    if (data->map->map[(int)(prev_y)][(int)(data->player->pos->x)] == '1')
        data->player->pos->x = prev_x;
}

void    rotate_player(t_game *data, double angle) // angle is ROTATE_SPEED in RADIANS
{
    double  prev_x;
    double  prev_y;

    prev_x = data->player->dir->x;
    prev_y = data->player->dir->y;
    data->player->dir->x = (prev_x * cos(angle)) - (prev_y * sin(angle));
    data->player->dir->y = (prev_x * sin(angle)) + (prev_y * cos(angle));

    prev_x = data->player->plan->x;
    prev_y = data->player->plan->y;
    data->player->plan->x = (prev_x * cos(angle)) - (prev_y * sin(angle));
    data->player->plan->y = (prev_x * sin(angle)) + (prev_y * cos(angle));
}