/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:20:13 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/14 09:14:16 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

int	ft_len_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		++i;
	return (i);
}

void	ft_pipe(t_pipex *data)
{
	pipe(data->fd);
	if (data->fd[0] == -1 || data->fd[1] == -1)
		ft_exit(data, 4, __func__);
}

void	ft_notfound(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, ": command not found\n", 20);
}

void	ft_get_flag(t_pipex *data, char **tab, int i)
{
	int	len;
	int	j;

	j = 0;
	len = ft_len_tab(tab);
	data->flags[i] = ft_calloc(sizeof(data->flags[i]), len + 1);
	if (!data->flags[i])
		ft_exit(data, 2, __func__);
	while (tab[j])
	{
		data->flags[i][j] = ft_strdup(tab[j]);
		++j;
	}
}

void	ft_open_files(t_pipex *data, int fdio[2])
{
	fdio[0] = open(data->infile, O_RDONLY);
	if (data->hd == 1)
		fdio[1] = open(data->outfile, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		fdio[1] = open(data->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fdio[0] == -1)
		perror(data->infile);
	if (fdio[1] == -1)
		ft_exit(data, 2, __func__);
}
