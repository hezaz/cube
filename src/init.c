/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:28:11 by baptistevie       #+#    #+#             */
/*   Updated: 2024/10/20 12:48:29 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void  load_texture(void *mlx_ptr, char *path, t_texture_img *texture)
{
    char    *full_path;

    full_path = ft_strjoin("textures/", path);
    garbage_collector(full_path, false, NULL);
    ft_printf("Chargement de la texture : %s\n", path);
    texture->img_ptr = mlx_xpm_file_to_image(mlx_ptr, full_path, &texture->width, &texture->height);
    if (!texture->img_ptr)
        ft_error("Erreur : Impossible de charger la texture");
    texture->data = mlx_get_data_addr(texture->img_ptr, &texture->bpp, &texture->size_line, &texture->endian);
    printf("Texture data address: %p\n", texture->data);
}

void    go_load_textures(t_game *game)
{
    load_texture(game->mlx->mlx_ptr, game->map->texture->north_wall, game->textures[0]);
    load_texture(game->mlx->mlx_ptr, game->map->texture->south_wall, game->textures[1]);
    load_texture(game->mlx->mlx_ptr, game->map->texture->east_wall, game->textures[2]);
    load_texture(game->mlx->mlx_ptr, game->map->texture->west_wall, game->textures[3]);
}

t_texture_img   *init_text_img(void)
{
    t_texture_img   *text_img;

    text_img = malloc(sizeof(t_texture_img));
    if (!text_img)
        ft_error("[init_text_img(...)] : malloc failed");
    garbage_collector(text_img, false, NULL);

    text_img->img_ptr = NULL;
    text_img->data = NULL;
    text_img->width = 0;
    text_img->height = 0;
    text_img->bpp = 0;
    text_img->size_line = 0;
    text_img->endian = 0;

    return(text_img);
}


t_vector    *init_vector(double x, double y)
{
    t_vector    *new_vect;

    new_vect = malloc(sizeof(t_vector));
    if (!new_vect)
        ft_error("[init_vector(...)] : vector malloc failed");
    garbage_collector(new_vect, false, NULL);
    new_vect->x = x;
    new_vect->y = y;
    return(new_vect);
}

t_player *init_player(t_map *map)
{
    t_player *player;
    int y, x;

    player = malloc(sizeof(t_player));
    if (!player)
        ft_error("[init_player(...)] : player malloc failed");
    garbage_collector(player, false,NULL);

    for (y = 0; y < map->height; y++)
    {
        for (x = 0; x < map->width; x++)
        {
            if (map->map[y][x] == 'N' || map->map[y][x] == 'S' ||
                map->map[y][x] == 'E' || map->map[y][x] == 'W')
            {
                player->pos = init_vector((double)x + 0.5f, (double)y + 0.5f);
                if (map->map[y][x] == 'N')
                    player->dir = init_vector(0.0f, -1.0f);
                else if (map->map[y][x] == 'S')
                    player->dir = init_vector(0.0f, 1.0f);
                else if (map->map[y][x] == 'E')
                    player->dir = init_vector(1.0f, 0.0f);
                else if (map->map[y][x] == 'W')
                    player->dir = init_vector(-1.0f, 0.0f);
                player->plan = init_vector(player->dir->y, -(player->dir->x));
                map->map[y][x] = '0'; // Remplacer par un espace libre
                return (player);
            }
        }
    }
    return (NULL);
}




t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("[init_map(...)] : t_map malloc failed");
	garbage_collector(map, false, NULL);
	map->height = 0;
	map->width = 0;
	map->texture = malloc(sizeof(t_texture));
	if (!map->texture)
		ft_error("[init_map(...)] : t_texture malloc failed");
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

	// image = malloc(sizeof(t_img));
	// if (!image)
	// 	ft_error("[init_img(...)] : t_img malloc failed");
	// garbage_collector(image, false);
	image.mlx_img = NULL;
	image.addr = NULL;
	image.bpp = 0;
	image.line_len = 0;
	image.endian = 0;
	return (image);
}

t_game *init_game(void)
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if (!game)
        ft_error("[init_game(...)] : t_game malloc failed");
    garbage_collector(game, false,NULL);
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
