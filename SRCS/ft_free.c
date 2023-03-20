/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:21:02 by cmartino          #+#    #+#             */
/*   Updated: 2023/03/17 15:43:48 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	ft_free(t_pipex data)
{
	ft_free_all(data.paths, ft_len_tab(data.paths));
	// ft_free_all(data.flags, ft_len_tab(data.flags));
	ft_free_all(data.cmd, ft_len_tab(data.cmd));
}
