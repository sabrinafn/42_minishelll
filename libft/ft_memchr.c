/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  feguimar < feguimar@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:34:59 by feguimar          #+#    #+#             */
/*   Updated: 2023/11/02 10:51:44 by  feguimar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ret;
	unsigned char	cc;
	size_t			i;

	cc = (unsigned char)c;
	i = 0;
	ret = (unsigned char *)s;
	while (i < n)
	{
		if (ret[i] == cc)
			return (ret + i);
		i++;
	}
	return (NULL);
}
