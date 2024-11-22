/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:43:25 by codespace         #+#    #+#             */
/*   Updated: 2024/11/22 11:57:12 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void	error_and_exit(char *message, t_game *game)
{
	printf("Error\n%s\n", message);
	close_game(game);	
	exit(1);
}

void	delete_node(void *ptr)
{
	free(ptr);
	ptr = NULL;
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
