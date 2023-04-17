/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:58:40 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/17 11:44:55 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_pipex {
	int		argc;
	char	*infile;
	char	*outfile;
	char	**argv;
	char	**envp;
	char	**cmds;
	char	**paths;
	char	***flags;
}				t_pipex;

int		ft_len_tab(char **tab);
char	**ft_get_envp_paths(char **envp);
void	ft_close(int fd);
void	ft_free(t_pipex *data);
void	ft_notfound(char *str);
void	ft_free_all(char **tab, int len);
void	ft_pipe(t_pipex *data, int (*fd)[2]);
void	ft_cmd_exist(t_pipex *data, int fdio[2]);
void	ft_open_files(t_pipex *data, int fdio[2]);
void	ft_get_flag(t_pipex *data, char **tab, int i);
void	ft_dup2(t_pipex *data, int fd, int input);
void	ft_execution(t_pipex *data, int *ret_value, int fdio[2]);
void	ft_exit(t_pipex *data, int type_err, const char *funct);
t_pipex	ft_init_data(int argc, char **argv, char **envp);

#endif
