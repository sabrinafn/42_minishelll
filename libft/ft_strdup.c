/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:06:38 by  feguimar         #+#    #+#             */
/*   Updated: 2025/01/28 00:57:43 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*ret;

	if (str == NULL)
		return (NULL);
	size = ft_strlen(str);
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (ret);
	ft_memcpy(ret, str, size + 1);
	return (ret);
}
