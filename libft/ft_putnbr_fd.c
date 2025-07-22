/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 06:32:07 by  feguimar         #+#    #+#             */
/*   Updated: 2023/11/04 10:24:59 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_helper(unsigned int value, int fd)
{
	if (value < 10)
		ft_putchar_fd('0' + value, fd);
	else
	{
		ft_putnbr_helper(value / 10, fd);
		ft_putnbr_helper(value % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	value;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		value = -n;
	}
	else
		value = n;
	ft_putnbr_helper(value, fd);
	return ;
}
