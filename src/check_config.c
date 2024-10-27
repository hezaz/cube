/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:33:34 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/10/27 17:56:58 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_rgb(t_rgb *rgb)
{
	return (rgb->r >= 0 && rgb->r < 256 && rgb->g >= 0 && rgb->g < 256
		&& rgb->b >= 0 && rgb->g < 256);
}

bool	is_valid_xpm(char *path)
{
	char	*tmp;
	char	*full_path;
	int		fd;

	tmp = path + ft_strlen(path) - 4;
	full_path = ft_strjoin("textures/", path);
	if (!full_path)
		return (false);
	fd = open(full_path, O_RDONLY);
	free(full_path);
	if (fd == -1)
		return (false);
	close(fd);
	return (ft_strnstr(tmp, ".xpm", 4));
}
