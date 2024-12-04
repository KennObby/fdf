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

int	main(int ac, char **av)
{
	t_env	*env;
	t_map	*map;

	if (ac != 2)
	{
		write(2, "Usage: ./fdf <map_file.fdf>\n", 26);
		return (EXIT_FAILURE);
	}
	map = parse_file(av[1], NULL);
	if (map == NULL)
	{
		free(map);
		error_exit("Failed to parse the map", NULL);
	}
	env = init_env(map);
	if (env == NULL)
		error_exit("Memory allocation failed for env", NULL);
	env->map = map;
	if (init_window(env) == -1)
	{
		free_map(map);
		free(env);
		error_exit("Failed to initialize graphics", NULL);
	}
	setup_event_hooks(env);
	render(env);
	mlx_loop(env->mlx);
	return (EXIT_SUCCESS);
}
