/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:23:16 by hedi              #+#    #+#             */
/*   Updated: 2024/10/19 18:12:21 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_input(t_game *game, int keysym)
{
	if (keysym == XK_w)
		move_player(game, 1);
	else if (keysym == XK_s)
		move_player(game, -1);
	else if (keysym == XK_a)
		rotate_player(game, DEG_TO_RAD(-ROTATE_SPEED));
	else if (keysym == XK_d)
		rotate_player(game, DEG_TO_RAD(ROTATE_SPEED));
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
		garbage_collector(NULL, true);
		exit(EXIT_FAILURE);
	}
	else
		handle_input(game, keysym);
	return (0);
}
