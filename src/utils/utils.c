/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:45:34 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/18 01:05:37 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	display_info(t_env *env, char *info)
{
	int			x;
	int			y;
	uint32_t	color;

	x = 10;
	y = 10;
	color = 0xFFFF00;
	mlx_string_put(env->mlx, env->win, x, y, color, info);
}

void	error_exit(const char *message, t_env *env)
{
	int	i;

	i = 0;
	while (message[i])
	{
		write(2, &message[i], 1);
		i++;
	}
	write(2, "\n", 1);
	if (env != NULL)
	{
		free_map(env->map);
		free_env(env);
	}
	exit(EXIT_FAILURE);
}

void	ft_free_split(char **split)
{
	int	i;

	if (split == NULL || *split == NULL)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
