/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:00:57 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/02 20:08:34 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	len;
	size_t	j;

	len = 0;
	while (s[len])
	{
		j = 0;
		while (reject[j])
		{
			if (s[len] == reject[j])
				return (len);
			j++;
		}
		len++;
	}
	return (len);
}
