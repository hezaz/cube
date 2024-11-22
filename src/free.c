/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:22:17 by baptistevie       #+#    #+#             */
/*   Updated: 2024/11/22 12:02:18 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures[i])
		{
			if (game->textures[i]->img_ptr)
			{
				mlx_destroy_image(game->mlx->mlx_ptr,
					game->textures[i]->img_ptr);
			}
		}
		i++;
	}
}

void	free_walls(t_game *game)
{
	if (game)
	{
		if (game->map)
		{
			if (game->map->texture)
			{
				if (game->map->texture->north_wall)
					free(game->map->texture->north_wall);
				if (game->map->texture->east_wall)
					free(game->map->texture->east_wall);
				if (game->map->texture->west_wall)
					free(game->map->texture->west_wall);
				if (game->map->texture->south_wall)
					free(game->map->texture->south_wall);
			}
		}
	}
}

void	free_mlx(t_game *game)
{
	if (game->img.mlx_img)
		mlx_destroy_image(game->mlx->mlx_ptr, game->img.mlx_img);
	if (game->mlx->win_ptr)
		mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
	if (game->mlx->mlx_ptr)
	{
		mlx_destroy_display(game->mlx->mlx_ptr);
		free(game->mlx->mlx_ptr);
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	free_walls(game);
	while (game->map->map[i])
	{
		free(game->map->map[i]);
		i++;
	}
	if (game->map->map)
		free(game->map->map);
	if (game->map)
		free(game->map);
}

void	free_player(t_player *player)
{
	if (player->dir)
		free(player->dir);
	if (player->plan)
		free(player->plan);
	if (player->pos)
		free(player->pos);
	if (player)
		free(player);
}