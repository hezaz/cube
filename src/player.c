/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:23:16 by hedi              #+#    #+#             */
/*   Updated: 2024/10/14 12:42:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void move_player(t_player *player, t_map *map, int dx, int dy)
// {
//     int new_x = player->x + dx;
//     int new_y = player->y + dy;

//     if (new_x >= 0 && new_x < map->width && new_y >= 0 && new_y < map->height &&
//         map->map[new_y][new_x] == '0')
//     {
//         player->x = new_x;
//         player->y = new_y;
//     }
// }

// void rotate_player(t_player *player, int direction)
// {
//     if (direction == 1) // Rotate right
//     {
//         if (player->direction == NORTH) player->direction = EAST;
//         else if (player->direction == EAST) player->direction = SOUTH;
//         else if (player->direction == SOUTH) player->direction = WEST;
//         else if (player->direction == WEST) player->direction = NORTH;
//     }
//     else if (direction == -1) // Rotate left
//     {
//         if (player->direction == NORTH) player->direction = WEST;
//         else if (player->direction == WEST) player->direction = SOUTH;
//         else if (player->direction == SOUTH) player->direction = EAST;
//         else if (player->direction == EAST) player->direction = NORTH;
//     }
// }

// int handle_keypress(int keysym, t_game *data)
// {
//     if (keysym == XK_Escape)
//         mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
//     else if (keysym == XK_w)
//         move_player(data->player, data->map, 0, -1); // Move up
//     else if (keysym == XK_s)
//         move_player(data->player, data->map, 0, 1); // Move down
//     else if (keysym == XK_a)
//         move_player(data->player, data->map, -1, 0); // Move left
//     else if (keysym == XK_d)
//         move_player(data->player, data->map, 1, 0); // Move right
//     else if (keysym == XK_Left)
//         rotate_player(data->player, -1); // Rotate left
//     else if (keysym == XK_Right)
//         rotate_player(data->player, 1); // Rotate right

//     return (0);
// }

// float deg_to_rad(float angle_in_degrees)
// {
//     return (angle_in_degrees * M_PI / 180.0f);
// }


// void move_player(t_player *player, t_map *map, float move_step) // to vectors
// {
//     float angle_rad = deg_to_rad(player->angle);
//     float new_x = player->x + cos(angle_rad) * move_step; // to vectors
//     float new_y = player->y + sin(angle_rad) * move_step; // to vectors

//     if (new_x >= 0 && new_x < map->width && new_y >= 0 && new_y < map->height &&
//         map->map[(int)new_y][(int)new_x] == '0')
//     {
//         player->x = new_x;
//         player->y = new_y;
//     }
// }


void handle_input(t_game *game, int keysym) // to vectors
{
    if (keysym == XK_w)
        move_player(game, 1); // Avancer
    else if (keysym == XK_s)
        move_player(game, -1); // Reculer
    else if (keysym == XK_a)
        rotate_player(game, DEG_TO_RAD(-ROTATE_SPEED)); // Tourner à gauche
    else if (keysym == XK_d)
        rotate_player(game, DEG_TO_RAD(ROTATE_SPEED)); // Tourner à droite

    // Normaliser l'angle (a garder ?)
//     if (game->player->angle < 0)
//         game->player->angle += 360.0f;
//     else if (game->player->angle >= 360.0f)
//         game->player->angle -= 360.0f;
}

int handle_keypress(int keysym, t_game *game)
{
    if (keysym == XK_Escape)
	{
        mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
		exit(EXIT_FAILURE);
	}
    else
        handle_input(game, keysym);

    return (0);
}
