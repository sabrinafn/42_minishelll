/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  feguimar < feguimar@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:09:20 by  feguimar         #+#    #+#             */
/*   Updated: 2023/10/28 20:41:16 by  feguimar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	size;
	size_t	index;

	if ((s == NULL) || (f == NULL))
		return (NULL);
	size = ft_strlen(s);
	index = 0;
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (ret);
	ret[size] = '\0';
	while (index < size)
	{
		ret[index] = f(index, s[index]);
		index++;
	}
	return (ret);
}
