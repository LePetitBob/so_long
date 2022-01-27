/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:50:18 by vduriez           #+#    #+#             */
/*   Updated: 2022/01/25 16:00:15 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit(char *strerr)
{
	write(2, strerr, ft_strlen(strerr));
	exit(2);
}

void	destroy_image(t_mlx *disp)
{
	mlx_destroy_image(disp->mlx, disp->img_e);
	mlx_destroy_image(disp->mlx, disp->img_f);
	mlx_destroy_image(disp->mlx, disp->img_w);
	mlx_destroy_image(disp->mlx, disp->img_c);
	mlx_destroy_image(disp->mlx, disp->img_p);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

int	ft_exit_mlx(t_mlx *disp)
{
	destroy_image(disp);
	mlx_destroy_window(disp->mlx, disp->win);
	mlx_destroy_display(disp->mlx);
	free(disp->mlx);
	free_map(disp->map);
	exit(1);
}

int	ft_exit_close(t_mlx *disp)
{
	free(disp->mlx);
	exit(1);
}
