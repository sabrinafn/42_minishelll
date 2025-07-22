/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:16:03 by  feguimar         #+#    #+#             */
/*   Updated: 2023/11/09 17:31:06 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c);

static void		place_words(const char *s, char c, char **ret);

static char		*get_word(const char *s, char c, int index);

static int		check_ret(char **ret, size_t words);

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**ret;

	words = count_words(s, c);
	ret = malloc((words + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	else
		while (words >= 0)
			ret[words--] = NULL;
	place_words(s, c, ret);
	if (!check_ret(ret, count_words(s, c)))
	{
		free(ret);
		return (0);
	}
	return (ret);
}

static size_t	count_words(const char *s, char c)
{
	size_t	index;
	int		is_first;
	size_t	words;

	words = 0;
	index = -1;
	is_first = 1;
	while (++index < (size_t)ft_strlen(s))
	{
		if (s[index] == c)
		{
			is_first = 1;
		}
		else
		{
			if (is_first)
			{
				words++;
				is_first = 0;
			}
		}
	}
	return (words);
}

static void	place_words(const char *s, char c, char **ret)
{
	size_t	index;
	size_t	word;
	int		is_first;

	index = -1;
	word = 0;
	is_first = 1;
	while (++index < (size_t)ft_strlen(s))
	{
		if (s[index] != c)
		{
			if (is_first)
			{
				ret[word] = get_word(s, c, index);
				is_first = 0;
				word++;
			}
		}
		else
			is_first = 1;
	}
}

static char	*get_word(const char *s, char c, int index)
{
	char	*ptr;

	ptr = ft_strchr(s + index, c);
	if (ptr == NULL)
		ptr = ft_strchr(s + index, '\0');
	return (ft_substr(s, index, ptr - (s + index)));
}

static int	check_ret(char **ret, size_t words)
{
	size_t	index;
	int		corrupted;

	corrupted = 0;
	index = 0;
	while (index < words)
	{
		if (ret[index] == NULL)
		{
			corrupted = 1;
			break ;
		}
		index++;
	}
	index = 0;
	while ((index < words) && corrupted)
	{
		if (ret[index] != NULL)
		{
			free(ret[index]);
			ret[index] = NULL;
		}
		index++;
	}
	return (!corrupted);
}
