/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  feguimar < feguimar@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:34:12 by feguimar          #+#    #+#             */
/*   Updated: 2023/11/02 10:58:16 by  feguimar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned long long int	total_mem;
	unsigned long long int	i;
	void					*ret;

	total_mem = 0;
	i = 0;
	while (i < size)
	{
		if (total_mem > (total_mem + nmemb))
			return (NULL);
		total_mem = total_mem + nmemb;
		i++;
	}
	ret = (malloc(total_mem));
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, total_mem);
	return (ret);
}
