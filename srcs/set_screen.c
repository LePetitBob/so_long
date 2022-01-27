/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:41:38 by vduriez           #+#    #+#             */
/*   Updated: 2022/01/27 18:29:54 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_imgs(t_mlx *disp, t_gnl *reading, char *map)
{
	int	i;

	reading->fd = open(map, O_RDONLY);
	reading->line = get_next_line(reading->fd);
	reading->height = 0;
	while (reading->line && reading->height < reading->heightmax)
	{
		i = -1;
		while (reading->line[++i])
			put_img_to_screen(reading, disp, i);
		reading->height++;
		free(reading->line);
		reading->line = get_next_line(reading->fd);
	}
	while (reading->line)
	{
		free(reading->line);
		reading->line = get_next_line(reading->fd);
	}
	free(reading->line);
	mlx_string_put(disp->mlx, disp->win, 16, 23, 0, "0");
	close(reading->fd);
}

void	put_img_to_screen(t_gnl *reading, t_mlx *disp, int i)
{
	if (reading->line[i] == '0')
		mlx_put_image_to_window(disp->mlx, disp->win,
			disp->img_f, i * 50, reading->height * 50);
	if (reading->line[i] == '1')
		mlx_put_image_to_window(disp->mlx, disp->win,
			disp->img_w, i * 50, reading->height * 50);
	if (reading->line[i] == 'P')
		mlx_put_image_to_window(disp->mlx, disp->win,
			disp->img_p, i * 50, reading->height * 50);
	if (reading->line[i] == 'W')
		mlx_put_image_to_window(disp->mlx, disp->win,
			disp->img_w, i * 50, reading->height * 50);
	if (reading->line[i] == 'E')
		mlx_put_image_to_window(disp->mlx, disp->win,
			disp->img_e, i * 50, reading->height * 50);
	if (reading->line[i] == 'C')
		mlx_put_image_to_window(disp->mlx, disp->win,
			disp->img_c, i * 50, reading->height * 50);
}
