/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:30:53 by baptistevie       #+#    #+#             */
/*   Updated: 2024/10/27 15:50:46 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(void *mlx_ptr, char *path, t_texture_img *texture)
{
	char	*full_path;

	full_path = ft_strjoin("textures/", path);
	garbage_collector(full_path, false, NULL);
	texture->img_ptr = mlx_xpm_file_to_image(mlx_ptr, full_path,
			&texture->width, &texture->height);
	if (!texture->img_ptr)
		ft_error("Erreur : Impossible de charger la texture");
	texture->data = mlx_get_data_addr(texture->img_ptr, &texture->bpp,
			&texture->size_line, &texture->endian);
}

void	go_load_textures(t_game *game)
{
	if (game->map->texture->north_wall_is_xpm)
		load_texture(game->mlx->mlx_ptr, game->map->texture->north_wall,
			game->textures[0]);
	else
		game->textures[0]->rgb = &(game->map->texture->north_wall_rgb);
	if (game->map->texture->south_wall_is_xpm)
		load_texture(game->mlx->mlx_ptr, game->map->texture->south_wall,
			game->textures[1]);
	else
		game->textures[1]->rgb = &(game->map->texture->south_wall_rgb);
	if (game->map->texture->east_wall_is_xpm)
		load_texture(game->mlx->mlx_ptr, game->map->texture->east_wall,
			game->textures[2]);
	else
		game->textures[2]->rgb = &(game->map->texture->east_wall_rgb);
	if (game->map->texture->west_wall_is_xpm)
		load_texture(game->mlx->mlx_ptr, game->map->texture->west_wall,
			game->textures[3]);
	else
		game->textures[3]->rgb = &(game->map->texture->west_wall_rgb);
}

t_texture_img	*init_text_img(void)
{
	t_texture_img	*text_img;

	text_img = malloc(sizeof(t_texture_img));
	if (!text_img)
		ft_error("[init_text_img(...)] : malloc failed");
	garbage_collector(text_img, false, NULL);
	text_img->img_ptr = NULL;
	text_img->rgb = NULL;
	text_img->data = NULL;
	text_img->width = 0;
	text_img->height = 0;
	text_img->bpp = 0;
	text_img->size_line = 0;
	text_img->endian = 0;
	return (text_img);
}

void	init_texture(t_texture *texture)
{
	texture->east_wall = NULL;
	texture->west_wall = NULL;
	texture->south_wall = NULL;
	texture->north_wall = NULL;
	texture->east_wall_is_xpm = -1;
	texture->west_wall_is_xpm = -1;
	texture->south_wall_is_xpm = -1;
	texture->north_wall_is_xpm = -1;
	init_rgb(&(texture->east_wall_rgb));
	init_rgb(&(texture->west_wall_rgb));
	init_rgb(&(texture->north_wall_rgb));
	init_rgb(&(texture->south_wall_rgb));
	init_rgb(&(texture->ceiling));
	init_rgb(&(texture->floor));
}

void	init_rgb(t_rgb *rgb)
{
	rgb->r = 0;
	rgb->g = 0;
	rgb->b = 0;
}
