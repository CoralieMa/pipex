/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:22:47 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/11 15:27:17 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

char	**ft_get_envp_paths(char **envp)
{
	char	**paths;
	int		i;

	if (!envp)
		return (NULL);
	i = -1;
	paths = NULL;
	while (envp[++i])
	{
		if (!ft_strncmp("PATH", envp[i], 4))
			paths = ft_split(&envp[i][5], ':');
	}
	return (paths);
}
