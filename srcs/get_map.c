/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:57:50 by vduriez           #+#    #+#             */
/*   Updated: 2022/01/27 20:08:33 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_map(t_gnl *reading, t_mlx *disp)
{
	int		i;

	i = -1;
	disp->map = malloc(sizeof(char *) * (reading->heightmax + 1));
	if (!disp->map)
		return ;
	disp->map[reading->heightmax] = NULL;
}

void	reading_init_values(t_gnl *reading)
{
	reading->line = NULL;
	reading->collectible = 0;
	reading->player = 0;
	reading->exits = 0;
	reading->height = 0;
	reading->length = 0;
	reading->heightmax = 0;
	reading->rect = 1;
	reading->walls = 1;
	reading->requisites = 1;
	reading->tmp = 0;
}
