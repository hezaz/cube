/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:55:19 by baptistevie       #+#    #+#             */
/*   Updated: 2024/11/22 14:25:18 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_game(t_game *game)
{
	free_textures(game);
	free(game->textures);
	free_map(game);
	if (game->player)
		free(game->player);
	free_mlx(game);
	if (game)
		free(game);
}