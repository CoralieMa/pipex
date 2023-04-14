/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:28:23 by cmartino          #+#    #+#             */
/*   Updated: 2023/04/13 10:46:52 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

void	ft_here_doc(char **argv)
{
	int		fdi;
	int		len;
	char	*line;

	len = ft_strlen(argv[2]);
	fdi = open("infile", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	line = get_next_line(0);
	while (ft_strncmp(argv[2], line, len))
	{
		write(fdi, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	free(get_next_line(-42));
	close(fdi);
}
