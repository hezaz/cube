/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:18:47 by baptistevie       #+#    #+#             */
/*   Updated: 2024/10/24 15:05:31 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void)data;
	(void)keysym;
	return (0);
}
