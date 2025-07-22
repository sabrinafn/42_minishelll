/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strteri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  feguimar < feguimar@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:09:20 by  feguimar         #+#    #+#             */
/*   Updated: 2023/10/28 20:48:49 by  feguimar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	size;
	size_t	index;

	if ((s == NULL) || (f == NULL))
		return ;
	size = ft_strlen(s);
	index = 0;
	while (index < size)
	{
		f(index, &s[index]);
		index++;
	}
	return ;
}
