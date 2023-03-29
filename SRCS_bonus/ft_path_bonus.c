/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:35:39 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/29 10:35:56 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes_bonus/pipex_bonus.h"

char	**ft_get_envp_paths(char **envp)
{
	char	**paths;
	int		i;

	if (!envp)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp("PATH", envp[i], 4))
			paths = ft_split(&envp[i][5], ':');
	}
	return (paths);
}
