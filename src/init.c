/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:28:11 by baptistevie       #+#    #+#             */
/*   Updated: 2024/10/27 14:00:49 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	*init_vector(double x, double y)
{
	t_vector	*new_vect;

	new_vect = malloc(sizeof(t_vector));
	if (!new_vect)
		ft_error("[init_vector(...)] : vector malloc failed");
	garbage_collector(new_vect, false, NULL);
	new_vect->x = x;
	new_vect->y = y;
	return (new_vect);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("[init_map(...)] : t_map malloc failed");
	garbage_collector(map, false, NULL);
	map->map_error = 0;
	map->height = 0;
	map->width = 0;
	map->texture = malloc(sizeof(t_texture));
	if (!map->texture)
		ft_error("[init_map(...)] : t_texture malloc failed");
	init_texture(map->texture);
	garbage_collector(map->texture, false, NULL);
	return (map);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		ft_error("[init_mlx(...)] : t_mlx malloc failed");
	garbage_collector(mlx, false, NULL);
	return (mlx);
}

t_img	init_img(void)
{
	t_img	image;

	image.mlx_img = NULL;
	image.addr = NULL;
	image.bpp = 0;
	image.line_len = 0;
	image.endian = 0;
	return (image);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("[init_game(...)] : t_game malloc failed");
	garbage_collector(game, false, NULL);
	game->map = init_map();
	game->mlx = init_mlx();
	game->img = init_img();
	game->textures[0] = init_text_img();
	game->textures[1] = init_text_img();
	game->textures[2] = init_text_img();
	game->textures[3] = init_text_img();
	game->player = NULL;
	return (game);
}
