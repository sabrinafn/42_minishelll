/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  feguimar < feguimar@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:35:43 by  feguimar         #+#    #+#             */
/*   Updated: 2023/10/28 18:49:09 by  feguimar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*ret;

	if (s1 == NULL)
		return (ft_strdup((char *)s1));
	if (s2 == NULL)
		return (ft_strdup((char *)s2));
	size = (ft_strlen(s1) + ft_strlen(s2));
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (ret);
	ret[0] = '\0';
	ft_strlcat(ret, s1, (size + 1));
	ft_strlcat(ret, s2, (size + 1));
	return (ret);
}
