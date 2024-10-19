/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:43:25 by codespace         #+#    #+#             */
/*   Updated: 2024/10/19 19:09:22 by hzaz             ###   ########.fr       */
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
		if (game)
		{
			if (((game->textures)[0])->img_ptr)
				mlx_destroy_image(game->mlx, ((game->textures)[0]));
			if (((game->textures)[1])->img_ptr)
				mlx_destroy_image(game->mlx, ((game->textures)[1]));
			if (((game->textures)[2])->img_ptr)
				mlx_destroy_image(game->mlx, ((game->textures)[2]));
			if (((game->textures)[3])->img_ptr)
				mlx_destroy_image(game->mlx, ((game->textures)[3]));
			if (((game->textures)[0])->data)
				free(((game->textures)[0])->data);
			if (((game->textures)[1])->data)
				free(((game->textures)[1])->data);
			if (((game->textures)[1])->data)
				free(((game->textures)[1])->data);
			if (((game->textures)[2])->data)
				free(((game->textures)[2])->data);
			if (((game->textures)[3])->data)
				free(((game->textures)[3])->data);
			mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
			if (game->mlx->mlx_ptr)
			{
				mlx_destroy_display(game->mlx->mlx_ptr);
   				free(game->mlx->mlx_ptr);
			}
			free(game->textures);
			
		}
		ft_lstclear(&garbage_list, delete);
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
