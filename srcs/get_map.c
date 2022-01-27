/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:57:50 by vduriez           #+#    #+#             */
/*   Updated: 2022/01/22 19:38:19 by vduriez          ###   ########.fr       */
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
