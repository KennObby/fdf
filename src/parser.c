/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:32:59 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/01 18:44:06 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

t_map	*parse_file(const char *file_path)
{
	s_map	**rows;
	int		max_width;
	int		height;
	char	*tokens;
	char	*current_row;
	char	*file;

	max_width = 0;
	height = 0;
	file = open(file_path, O_RDONLY);
	if (file == NULL)
	{
		perror("Error: Cannot open file.");
		return (NULL);
	}
	while(!EOF(file))
	{
		line = get_next_line(file);
		if (line == NULL)
			break ;
		tokens = ft_split(line, char c);
		current_row = ft_lstnew();
	}
}

void	free_map(t_map *map)
{
}
