/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:36:50 by codespace         #+#    #+#             */
/*   Updated: 2024/11/22 12:08:16 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	render_background(t_img *img, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < WINDOW_HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WINDOW_WIDTH)
// 		{
// 			img_pix_put(img, j++, i, color);
// 		}
// 		++i;
// 	}
// }

int	initialize_mlx(t_game *data)
{
	data->mlx->mlx_ptr = mlx_init();
	if (data->mlx->mlx_ptr == NULL)
		return (0);
	data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "cub3d");
	if (data->mlx->win_ptr == NULL)
		return (0);
	return (1);
}

int	initialize_game_data(t_game *data, char *map_path)
{
	data->map = get_map(map_path);
	if (data->map == NULL || data->map->map_error)
		error_and_exit("Map or cub file invalid", data);
	data->player = init_player(data->map);
	if (!data->player)
		return (0);
	go_load_textures(data);
	check_map(data);
	data->img.mlx_img = mlx_new_image(data->mlx->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (data->img.mlx_img == NULL)
		return (0);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (data->img.addr == NULL)
		return (0);
	return (1);
}

int	handle_exit(t_game *game)
{
	close_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	setup_hooks(t_game *data)
{
	mlx_loop_hook(data->mlx->mlx_ptr, &render_3d, data);
	mlx_hook(data->mlx->win_ptr, KeyPress, KeyPressMask, &handle_keypress,
		data);
	mlx_hook(data->mlx->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		data);
	mlx_hook(data->mlx->win_ptr, 17, 0L, &handle_exit, data);
}

int	main(int ac, char **av)
{
	t_game	*data;
	int		fd;

	if (ac != 2)
		return (ft_error("Bad arguments"), 0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("Map file isn't valid"), 0);
	close(fd);
	data = init_game();
	if (!initialize_mlx(data))
		return (MLX_ERROR);
	if (!initialize_game_data(data, av[1]))
		return (1);
	setup_hooks(data);
	mlx_loop(data->mlx->mlx_ptr);
	close_game(data);
	// garbage_collector(NULL, true, data); // GC_TRUE
	return (1);
}
