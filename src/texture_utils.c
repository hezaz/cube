/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:23:40 by hedi              #+#    #+#             */
/*   Updated: 2024/10/20 16:24:18 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_spaces(char *line)
{
	while (*line == ' ')
		line++;
	return (line);
}

int	is_rgb_color(char *line)
{
	int	commas;

	commas = 0;
	while (*line)
	{
		if (*line == ',')
			commas++;
		else if (!ft_isdigit(*line) && *line != ' ')
			return (0);
		line++;
	}
	return (commas == 2);
}

t_rgb	parse_rgb(char *line)
{
	t_rgb	color;
	char	**values;

	values = ft_split(line, (char const *)",");
	if (!values || !values[0] || !values[1] || !values[2])
		error_and_exit("Invalid RGB color", NULL);
	color.r = ft_atoi(values[0]);
	color.g = ft_atoi(values[1]);
	color.b = ft_atoi(values[2]);
	printf("parseRGB: %d %d %d\n", color.r, color.g, color.b);
	free(values[0]);
	values[0] = NULL;
	free(values[1]);
	values[1] = NULL;
	free(values[2]);
	values[2] = NULL;
	free(values);
	values = NULL;
	return (color);
}
