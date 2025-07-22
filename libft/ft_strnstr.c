/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  feguimar < feguimar@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:35:19 by feguimar          #+#    #+#             */
/*   Updated: 2023/11/02 10:53:03 by  feguimar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b_pos;
	size_t	l_pos;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	if ((ft_strlen(big) == 0) || (len == 0))
		return (NULL);
	b_pos = 0;
	while (1)
	{
		l_pos = 0;
		while (big[b_pos + l_pos] == little[l_pos])
		{
			l_pos++;
			if (little[l_pos] == '\0')
				return ((char *)&big[b_pos]);
			if ((big[b_pos + l_pos] == '\0') || (b_pos + l_pos == len))
				return (NULL);
		}
		b_pos++;
		if ((big[b_pos] == '\0') || (b_pos == len))
			return (NULL);
	}
	return (NULL);
}
