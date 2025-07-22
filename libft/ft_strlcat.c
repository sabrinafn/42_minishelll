/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  feguimar < feguimar@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:05:38 by feguimar          #+#    #+#             */
/*   Updated: 2023/11/02 22:59:43 by  feguimar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*end_dst;
	size_t	dst_size;

	dst_size = ft_strlen(dst);
	if ((size == 0) || (size <= (size_t)ft_strlen(dst)))
		return (ft_strlen(src) + size);
	end_dst = ft_strchr(dst, '\0');
	if ((size - dst_size) > 0)
		ft_strlcpy(end_dst, src, size - dst_size);
	return (ft_strlen(src) + dst_size);
}
