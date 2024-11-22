/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:23:16 by hedi              #+#    #+#             */
/*   Updated: 2024/11/22 11:58:55 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_input(t_game *game, int keysym)
{
	if (keysym == XK_w)
		move_player(game, 1, 0);
	else if (keysym == XK_s)
		move_player(game, -1, 0);
	else if (keysym == XK_a)
		move_player(game, 0, -1);
	else if (keysym == XK_d)
		move_player(game, 0, 1);
	else if (keysym == XK_Left)
		rotate_player(game, deg_to_rad(-ROTATE_SPEED));
	else if (keysym == XK_Right)
		rotate_player(game, deg_to_rad(ROTATE_SPEED));
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		close_game(game);
		exit(EXIT_FAILURE);
	}
	else
		handle_input(game, keysym);
	return (0);
}
