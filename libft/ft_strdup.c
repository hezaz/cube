/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:24:12 by absalhi           #+#    #+#             */
/*   Updated: 2024/10/12 19:50:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tab;
	size_t	len;
	int		i;

	len = ft_strlen(s1);
	tab = (char *) ft_calloc(len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	i = -1;
	while (s1[++i])
		tab[i] = s1[i];
	return (tab);
}

char	*ft_strndup(const char *s1, int n)
{
	char	*tab;
	size_t	len;
	int		i;

	len = ft_strlen(s1);
	tab = (char *) ft_calloc(len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		tab[i] = s1[i];
		i++;
	}
	return (tab);
}
