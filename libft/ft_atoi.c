/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:33:04 by feguimar          #+#    #+#             */
/*   Updated: 2023/11/03 15:50:06 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c);

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	i;
	int	sign;

	ret = 0;
	i = 0;
	while (ft_is_space(nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '-')
		sign = -1;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
		i++;
	while (ft_isdigit(nptr[i]))
	{
		ret = ret * 10;
		ret = ret + (nptr[i] - '0');
		i++;
	}
	return (ret * sign);
}

static int	ft_is_space(char c)
{
	char	*check;

	check = " \v\t\r\n\f";
	while (*check != '\0')
	{
		if (c == *check)
			return (1);
		check++;
	}
	return (0);
}
