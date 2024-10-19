/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:18:47 by baptistevie       #+#    #+#             */
/*   Updated: 2024/09/30 09:25:56 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	(void)data;
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void)data;
	(void)keysym;
	// ft_printf("Keyrelease: %d\n", keysym);
	return (0);
}
