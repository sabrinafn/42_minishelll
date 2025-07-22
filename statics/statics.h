/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statics.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:09:05 by fernando          #+#    #+#             */
/*   Updated: 2025/02/02 17:50:26 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATICS_H
# define STATICS_H

# include "../minishell.h"

t_args_lst	**args_list(void);
t_envp_lst	**env_vars_list(int clear);
int			*current_exit_code(void);
pid_t		*prog_pid(void);
pid_t		*running_loop(void);
t_command	**command_lst(void);
pid_t		*last_pid(void);
void		free_statics(void);
int			*child_process(void);
t_command	**curr_cmd(void);

#endif
