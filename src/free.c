/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:22:17 by baptistevie       #+#    #+#             */
/*   Updated: 2024/11/24 15:17:51 by hzaz             ###   ########.fr       */
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
			free(game->textures[i]);
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
				free(game->map->texture);
			}
		}
	}
}

void	free_mlx(t_game *game)
{
	if (game->img.mlx_img)
		mlx_destroy_image(game->mlx->mlx_ptr, game->img.mlx_img);
	if (game->mlx)
	{
		if (game->mlx->win_ptr)
			mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
		if (game->mlx->mlx_ptr)
		{
			mlx_destroy_display(game->mlx->mlx_ptr);
			free(game->mlx->mlx_ptr);
		}
		free(game->mlx);
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		if (game->map->texture)
			free_walls(game);
		if (game->map->map)
		{
			while (i < game->map->height)
			{
				free(game->map->map[i]);
				i++;
			}
			free(game->map->map);
		}
		free(game->map);
	}
}

void	free_player(t_player *player)
{
	if (player)
	{
		if (player->dir)
			free(player->dir);
		if (player->plan)
			free(player->plan);
		if (player->pos)
			free(player->pos);
		free(player);
	}
}
