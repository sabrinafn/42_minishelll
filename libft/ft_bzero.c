/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  feguimar < feguimar@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:33:19 by feguimar          #+#    #+#             */
/*   Updated: 2023/11/02 10:48:54 by  feguimar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*pos;

	i = 0;
	pos = (unsigned char *)s;
	while (i < n)
	{
		pos[i] = '\0';
		i++;
	}
	return ;
}
