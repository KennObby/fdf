/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:13:56 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/17 17:19:36 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

uint32_t	ft_atoi_base(const char *str)
{
	uint32_t	num;

	num = 0;
	if (str == NULL)
		return (0xFFFFFF);
	while (*str)
	{
		num <<= 4;
		if (*str >= '0' && *str <= '9')
			num += *str - '0';
		else if (*str >= 'A' && *str <= 'F')
			num += *str - 'A' + 10;
		else if (*str >= 'a' && *str <= 'f')
			num += *str - 'a' + 10;
		else
			break ;
		str++;
	}
	return (num);
}
