/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:00:42 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/31 14:30:57 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../minishell.h"

void		create_node(t_args_lst **args_lst, const char *str, int start,
				int len);
void		ft_lexer(t_args_lst **split);
t_args_lst	*ft_lst_split(char *str);
int			ft_strcmp(const char *s1, const char *s2);
void		split_by_quotes(t_args_lst **split, char *str, int *i);
void		split_by_redirects(t_args_lst **split, char *str, int *i);
int			ends_space_block(char c);
void		split_by_spaces(t_args_lst **split, char *str, int i);
bool		quotes_are_balanced(char *str);
int			is_operator(char *str);
int			is_str_quoted(char *str);

#endif
