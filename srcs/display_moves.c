/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:04:10 by vduriez           #+#    #+#             */
/*   Updated: 2022/01/20 00:39:39 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_left(t_mlx *disp)
{
	mlx_put_image_to_window(disp->mlx, disp->win, disp->img_f,
		50 * disp->pos[0], 50 * disp->pos[1]);
	disp->pos[0]--;
	mlx_put_image_to_window(disp->mlx, disp->win, disp->img_p,
		50 * disp->pos[0], 50 * disp->pos[1]);
}

void	move_right(t_mlx *disp)
{
	mlx_put_image_to_window(disp->mlx, disp->win, disp->img_f,
		50 * disp->pos[0], 50 * disp->pos[1]);
	disp->pos[0]++;
	mlx_put_image_to_window(disp->mlx, disp->win, disp->img_p,
		50 * disp->pos[0], 50 * disp->pos[1]);
}

void	move_up(t_mlx *disp)
{
	mlx_put_image_to_window(disp->mlx, disp->win, disp->img_f,
		50 * disp->pos[0], 50 * disp->pos[1]);
	disp->pos[1]--;
	mlx_put_image_to_window(disp->mlx, disp->win, disp->img_p,
		50 * disp->pos[0], 50 * disp->pos[1]);
}

void	move_down(t_mlx *disp)
{
	mlx_put_image_to_window(disp->mlx, disp->win, disp->img_f,
		50 * disp->pos[0], 50 * disp->pos[1]);
	disp->pos[1]++;
	mlx_put_image_to_window(disp->mlx, disp->win, disp->img_p,
		50 * disp->pos[0], 50 * disp->pos[1]);
}
