/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  feguimar < feguimar@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:05:38 by feguimar          #+#    #+#             */
/*   Updated: 2023/10/28 18:52:34 by  feguimar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dst == NULL)
		return (ft_strlen(src));
	if (src == NULL)
	{
		dst[0] = '\0';
		return (ft_strlen(src));
	}
	if (size <= 0)
		return (ft_strlen(src));
	if ((size_t)ft_strlen(src) + 1 < size)
		size = ft_strlen(src) + 1;
	while ((i < (size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[size -1] = '\0';
	return (ft_strlen(src));
}
