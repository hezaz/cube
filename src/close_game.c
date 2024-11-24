/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:55:19 by baptistevie       #+#    #+#             */
/*   Updated: 2024/11/24 13:17:28 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_game(t_game *game)
{
	if (game)
	{
		if (game->player)
			free_player(game->player);
		if (game->textures[0] || game->textures[1]
				|| game->textures[2] || game->textures[3])
			free_textures(game);
		free_mlx(game);
		if (game->map)	
			free_map(game);
		free(game);
	}
}