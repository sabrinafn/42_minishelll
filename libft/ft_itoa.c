/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:00:44 by  feguimar         #+#    #+#             */
/*   Updated: 2023/11/19 16:25:52 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_helper(char *ret, int *i, unsigned int n)
{
	if (n < 10)
	{
		ret[*i] = '0' + n;
		(*i)++;
	}
	else
	{
		ft_itoa_helper(ret, i, n / 10);
		ft_itoa_helper(ret, i, n % 10);
	}
}

char	*ft_itoa(int n)
{
	char			*ret;
	char			*f_ret;
	int				i;
	unsigned int	val;

	i = 0;
	val = (unsigned int)n;
	ret = malloc(12 * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, 12);
	if (n == 0)
		ret[i] = '0';
	else if (n < 0)
	{
		ret[i] = '-';
		val = -val;
		i++;
	}
	if (val > 0)
		ft_itoa_helper(ret, &i, val);
	f_ret = ft_strdup(ret);
	free(ret);
	return (f_ret);
}
