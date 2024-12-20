/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 07:30:12 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/04 07:48:00 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_env	*env;
	t_map	*map;
	t_list	*lines;

	if (ac != 2)
		error_exit("Usage: ./fdf <map_file.fdf>\n", NULL);
	map = parse_file(av[1], &lines, NULL);
	if (!map)
	{
		free(map);
		error_exit("Failed to parse the map file", NULL);
	}
	env = init_env(NULL);
	if (!env)
		error_exit("Failed to parse the map file", NULL);
	env->map = map;
	center_map(env, map);
	if (init_window(env) == -1)
	{
		free_map(map);
		free(env);
		error_exit("Error: Failed to initialize window", NULL);
	}
	env->image = init_image(env);
	if (!env->image)
		error_exit("Error: Failed to initialize image", NULL);
	compute_sincos(&env->transform);
	setup_event_hooks(env);
	render(env);
	mlx_loop(env->mlx);
	free_env(env);
	return (EXIT_SUCCESS);
}
