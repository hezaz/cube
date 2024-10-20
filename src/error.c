/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:43:25 by codespace         #+#    #+#             */
/*   Updated: 2024/10/20 18:19:18 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

static void delete (void *ptr);

void	*garbage_collector(void *ptr, bool clean, t_game *game)
{
	static t_list	*garbage_list;

	if (clean)
	{
		if (clean)
		{
    		for (int i = 0; i < 4; i++)
			{
				printf("Freeing texture %d, img_ptr: %p, data: %p\n", i, game->textures[i]->img_ptr, game->textures[i]->data);
        		if (game->textures[i])
				{
            		if (game->textures[i]->img_ptr)
					{
						printf("Destroying image %d\n", i);
                		mlx_destroy_image(game->mlx->mlx_ptr, game->textures[i]->img_ptr);

					}

					// if (game->textures[i]->data)
                	// {
					// 	printf("not Freeing data for texture %d\n", i);
					// 	// free(game->textures[i]->data);
            		// }
				}
            	// free(game->textures[i]);
        }
		if (game->map->texture->north_wall)
			free(game->map->texture->north_wall);
		if (game->map->texture->east_wall)
			free(game->map->texture->east_wall);
		if (game->map->texture->west_wall)
			free(game->map->texture->west_wall);
		if (game->map->texture->south_wall)
			free(game->map->texture->south_wall);
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
		ft_lstclear(&garbage_list, delete);
		exit(1);
		return (NULL);
	}
	else
	{
		ft_lstadd_back(&garbage_list, ft_lstnew(ptr));
		return (ptr);
	}
}

static void delete (void *ptr)
{
	free(ptr);
	ptr = NULL;
}
