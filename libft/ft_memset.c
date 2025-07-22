/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  feguimar < feguimar@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:35:15 by feguimar          #+#    #+#             */
/*   Updated: 2023/10/28 17:28:05 by  feguimar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*pos;
	size_t	i;

	pos = (char *)s;
	i = 0;
	while (i < n)
	{
		pos[i] = c;
		i++;
	}
	return (s);
}
