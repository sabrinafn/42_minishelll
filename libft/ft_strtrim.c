/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar < feguimar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:18:53 by feguimar          #+#    #+#             */
/*   Updated: 2023/11/09 10:44:52 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*ret_f;
	size_t	start;
	size_t	end;

	if ((ft_strlen(s1) == 0) || (ft_strlen(set) == 0))
		return (ft_strdup(s1));
	start = 0;
	while ((s1[start] != '\0') && (ft_is_set(s1[start], set)))
		start++;
	ret = ft_strdup(s1 + start);
	if (ret == NULL)
		return (NULL);
	end = ft_strlen(ret);
	while (ft_is_set(ret[end - 1], set))
		end--;
	ret[end] = '\0';
	ret_f = ft_strdup(ret);
	free(ret);
	return (ret_f);
}

static int	ft_is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
