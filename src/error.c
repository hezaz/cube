/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:43:25 by codespace         #+#    #+#             */
/*   Updated: 2024/10/24 14:55:51 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

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

void	delete_node(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	free_walls(t_game *game)
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

void	*garbage_collector(void *ptr, bool clean, t_game *game)
{
	static t_list	*garbage_list;

	if (clean)
	{
		free_textures(game);
		free_walls(game);
		free_mlx(game);
		ft_lstclear(&garbage_list, delete_node);
		exit(1);
		return (NULL);
	}
	else
	{
		ft_lstadd_back(&garbage_list, ft_lstnew(ptr));
		return (ptr);
	}
}
