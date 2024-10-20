/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:43:25 by codespace         #+#    #+#             */
/*   Updated: 2024/10/20 12:26:45 by bvieilhe         ###   ########.fr       */
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
					if (game->textures[i]->data)
                	{
						printf("not Freeing data for texture %d\n", i);
						// free(game->textures[i]->data);
            		}
				}
            	// free(game->textures[i]);
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
