/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:46:33 by vduriez           #+#    #+#             */
/*   Updated: 2022/01/27 20:11:23 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	extension_check(char *ext, char *file)
{
	int	i;
	int	j;
	int	path;

	i = 0;
	j = 0;
	path = 0;
	while (file[j])
		j++;
	if (j <= 4)
		return (0);
	j -= 4;
	if (!ft_strncmp(file + j, ext, 5) && file[j - 1] != '/')
		return (1);
	return (0);
}

void	err_img(char *msg, t_mlx *disp)
{
	if (disp->img_e)
		mlx_destroy_image(disp->mlx, disp->img_e);
	if (disp->img_w)
		mlx_destroy_image(disp->mlx, disp->img_w);
	if (disp->img_f)
		mlx_destroy_image(disp->mlx, disp->img_f);
	if (disp->img_c)
		mlx_destroy_image(disp->mlx, disp->img_c);
	if (disp->img_p)
		mlx_destroy_image(disp->mlx, disp->img_p);
	write(2, msg, ft_strlen(msg));
	mlx_destroy_window(disp->mlx, disp->win);
	mlx_destroy_display(disp->mlx);
	free(disp->mlx);
	free_map(disp->map);
	exit(1);
}

void	sprite_check(t_mlx *disp, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY, O_NOCTTY, __O_NOFOLLOW);
	if (fd < 0 || !extension_check(".xpm", path))
		err_img("Error\nSprite must be an existing .xpm file\n", disp);
	close(fd);
}

void	create_imgs(t_mlx *disp)
{
	int	img_h;
	int	img_w;

	sprite_check(disp, disp->rp_e = "./sprites/exit.xpm");
	disp->img_e = mlx_xpm_file_to_image(disp->mlx, disp->rp_e, &img_w, &img_h);
	sprite_check(disp, disp->rp_f = "./sprites/floor.xpm");
	disp->img_f = mlx_xpm_file_to_image(disp->mlx, disp->rp_f, &img_w, &img_h);
	sprite_check(disp, disp->rp_w = "./sprites/wall.xpm");
	disp->img_w = mlx_xpm_file_to_image(disp->mlx, disp->rp_w, &img_w, &img_h);
	sprite_check(disp, disp->rp_c = "./sprites/collectible.xpm");
	disp->img_c = mlx_xpm_file_to_image(disp->mlx, disp->rp_c, &img_w, &img_h);
	sprite_check(disp, disp->rp_p = "./sprites/player.xpm");
	disp->img_p = mlx_xpm_file_to_image(disp->mlx, disp->rp_p, &img_w, &img_h);
}
