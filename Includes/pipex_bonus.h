/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:19:45 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/12 15:19:02 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <limits.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

typedef struct s_pipex {
	int		argc;
	int		fd[2];
	int		hd;
	char	*infile;
	char	*outfile;
	char	**argv;
	char	**envp;
	char	**cmds;
	char	**paths;
	char	***flags;
}				t_pipex;

int		ft_len_tab(char **tab);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	**ft_get_envp_paths(char **envp);
void	ft_free(t_pipex *data);
void	ft_notfound(char *str);
void	ft_free_all(char **tab, int len);
void	ft_pipe(t_pipex *data);
void	ft_here_doc(char **argv);
void	ft_cmd_exist(t_pipex *data, int fdio[2]);
void	ft_open_files(t_pipex *data, int fdio[2]);
void	ft_get_flag(t_pipex *data, char **tab, int i);
void	ft_execution(t_pipex *data, int *ret_value, int fdio[2]);
void	ft_exit(t_pipex *data, int type_err, const char *funct);
t_pipex	ft_init_data(int argc, char **argv, char **envp);
t_pipex	ft_init_data_here_doc(int argc, char **argv, char **envp);

#endif
