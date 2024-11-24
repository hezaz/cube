/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:28:11 by baptistevie       #+#    #+#             */
/*   Updated: 2024/11/24 15:24:25 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	*init_vector(double x, double y)
{
	t_vector	*new_vect;

	new_vect = malloc(sizeof(t_vector));
	if (!new_vect)
		ft_error("[init_vector(...)] : vector malloc failed");
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
	map->map_error = 0;
	map->valid_map = 0;
	map->map_hasnl = 0;
	map->nbr_p = 0;
	map->height = 0;
	map->width = 0;
	map->texture = malloc(sizeof(t_texture));
	if (!map->texture)
		ft_error("[init_map(...)] : t_texture malloc failed");
	init_texture(map->texture);
	return (map);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		ft_error("[init_mlx(...)] : t_mlx malloc failed");
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
