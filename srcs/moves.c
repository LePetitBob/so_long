/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:59:27 by vduriez           #+#    #+#             */
/*   Updated: 2022/01/21 17:19:46 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_move(t_mlx *disp)
{
	char	*moves;

	moves = ft_itoa(disp->move_count + 1);
	disp->move_count++;
	printf("moves : %d\n", disp->move_count);
	mlx_put_image_to_window(disp->mlx, disp->win, disp->img_w, 0, 0);
	mlx_string_put(disp->mlx, disp->win, 16, 23, 0, moves);
	free(moves);
}

int	can_move_x(t_mlx *disp, char dest)
{
	if (dest == 'l')
	{
		if (disp->map[disp->pos[1]][disp->pos[0] - 1] == '1'
			|| (disp->map[disp->pos[1]][disp->pos[0] - 1] == 'E'
			&& disp->to_collect > 0))
			return (0);
		return (1);
	}
	if (dest == 'r')
	{
		if (disp->map[disp->pos[1]][disp->pos[0] + 1] == '1'
			|| (disp->map[disp->pos[1]][disp->pos[0] + 1] == 'E'
			&& disp->to_collect > 0))
			return (0);
	}
	return (1);
}

int	can_move_y(t_mlx *disp, char dest)
{
	if (dest == 'u')
	{
		if (disp->map[disp->pos[1] - 1][disp->pos[0]] == '1'
			|| (disp->map[disp->pos[1] - 1][disp->pos[0]] == 'E'
			&& disp->to_collect > 0))
			return (0);
	}
	if (dest == 'd')
	{
		if (disp->map[disp->pos[1] + 1][disp->pos[0]] == '1'
			|| (disp->map[disp->pos[1] + 1][disp->pos[0]] == 'E'
			&& disp->to_collect > 0))
			return (0);
	}
	return (1);
}

void	move_x(t_mlx *disp, int keycode)
{
	if ((keycode == 65361 || keycode == 97) && can_move_x(disp, 'l'))
	{
		print_move(disp);
		move_left(disp);
	}
	if ((keycode == 65363 || keycode == 100) && can_move_x(disp, 'r'))
	{
		print_move(disp);
		move_right(disp);
	}
	if (disp->map[disp->pos[1]][disp->pos[0]] == 'C')
		disp->to_collect--;
	if (disp->map[disp->pos[1]][disp->pos[0]] == 'C')
		disp->map[disp->pos[1]][disp->pos[0]] -= 19;
	if (disp->map[disp->pos[1]][disp->pos[0]] == 'E' && disp->to_collect < 0)
		exit(1);
}

void	move_y(t_mlx *disp, int keycode)
{
	if ((keycode == 65362 || keycode == 119) && can_move_y(disp, 'u'))
	{
		print_move(disp);
		move_up(disp);
	}
	if ((keycode == 65364 || keycode == 115) && can_move_y(disp, 'd'))
	{
		print_move(disp);
		move_down(disp);
	}
	if (disp->map[disp->pos[1]][disp->pos[0]] == 'C')
		disp->to_collect--;
	if (disp->map[disp->pos[1]][disp->pos[0]] == 'C')
		disp->map[disp->pos[1]][disp->pos[0]] -= 19;
}
