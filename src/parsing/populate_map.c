/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:52:28 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/03 22:07:09 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	populate_map(t_map *map, t_list *head, t_env *env)
{
	t_list	*current;
	t_point	point;
	char	**tokens;
	char	**split_z_color;
	int		x;
	int		y;
	int		z;

	y = 0;
	current = head;
	while (current != NULL && y < map->height)
	{
		tokens = ft_split(current->content, ' ');
		if (tokens == NULL)
			error_exit("Memory allocation failed during split", env);
		x = 0;
		while (x < map->width)
		{
			if (tokens[x] != NULL)
			{
				split_z_color = ft_split(tokens[x], ',');
				if (split_z_color == NULL)
					error_exit("Memory allocation failed", env);
				if (split_z_color[0])
					z = ft_atoi(split_z_color[0]);
				else
					z = 0;
				if (split_z_color[1])
					point.color = ft_atoi_base(split_z_color[1]);
				else
					point.color = 0xFFFFFF;
				point = create_point(x, y, z, point.color);
				ft_free_split(split_z_color);
			}
			else
			{
				z = 0;
				point = create_point(x, y, z, 0xFFFFFF);
			}
			map->points[y][x] = point;
			x++;
		}
		ft_free_split(tokens);
		y++;
		current = current->next;
	}
}
