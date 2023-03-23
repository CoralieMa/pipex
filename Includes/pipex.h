/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:34:38 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/21 11:37:19 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef	struct s_pipex {
	char	*infile;
	char	*outfile;
	char	**cmd;
	char	**envp;
	char	**flags;
	char	**paths;
}				t_pipex;

int		ft_exit(int code);
int		ft_len_tab(char **tab);
char	*ft_get_flags(char *tab);
char	*ft_my_strcpy(char *src, char *dst);
char	**ft_get_envp_paths(char **envp);
void	ft_free(t_pipex data);
void	ft_cmd_execution(t_pipex data);
t_pipex	ft_init(char **argv, char **envp);
t_pipex ft_cmd_exist(int argc, char **argv, t_pipex data);

#endif