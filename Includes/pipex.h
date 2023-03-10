/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:34:38 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/07 10:30:12 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
# include "../libft/libft.h"

typedef	struct s_pipex {
	char	***cmds;
	char	**paths;
}				t_pipex;

int		ft_len_tab(char **tab);
int		ft_exit(int code);
int 	ft_cmd_exist(int argc, char **argv, t_pipex data);
char	**ft_get_envp_paths(char **envp);

#endif