/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:11:26 by vduriez           #+#    #+#             */
/*   Updated: 2022/01/27 19:56:41 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	reading_set(t_gnl *reading, char *map)
{
	int		read_ret[2];
	char	*sample;

	sample = malloc(sizeof(char) * 5);
	if (!sample)
		return ;
	read_ret[1] = open(map, O_RDONLY);
	read_ret[0] = read(read_ret[1], sample, 4);
	sample[4] = '\0';
	close(read_ret[1]);
	if (read_ret[0] < 1 || !printable(sample))
	{
		free(sample);
		ft_exit("Error\nThe map is invalid\n");
	}
	free(sample);
	reading = (t_gnl){0};
	reading->line = NULL;
	reading->rect = 1;
	reading->walls = 1;
	reading->requisites = 1;
}

void	reading_init(t_gnl *reading, char *map)
{
	int	print;

	reading_set(reading, map);
	reading->fd = open(map, O_RDONLY);
	if (reading->fd < 0)
		ft_exit("Error\nFailed to open map\n");
	reading->line = get_next_line(reading->fd);
	print = printable(reading->line);
	if (print)
		reading->length = ft_strlen(reading->line);
	while (reading->line && reading->line[0] != '\n' && print)
	{
		reading->heightmax++;
		free(reading->line);
		reading->line = get_next_line(reading->fd);
	}
	while (reading->line)
	{
		free(reading->line);
		reading->line = get_next_line(reading->fd);
	}
	free(reading->line);
	close(reading->fd);
}

int	key_hook(int keycode, t_mlx *disp)
{
	if (keycode == 65307)
		ft_exit_mlx(disp);
	if (keycode == 65361 || keycode == 97
		|| keycode == 65363 || keycode == 100)
		move_x(disp, keycode);
	if (keycode == 65362 || keycode == 119
		|| keycode == 65364 || keycode == 115)
		move_y(disp, keycode);
	if (disp->to_collect <= 0 && disp->map[disp->pos[1]][disp->pos[0]] == 'E')
		ft_exit_mlx(disp);
	return (0);
}

int	main(int ac, char **av)
{
	t_gnl	reading;
	t_mlx	disp;

	disp = (t_mlx){0};
	if (ac != 2)
		ft_exit("Error\nExpected format :\n$> ./so_long map.ber\n");
	if (!extension_check(".ber", av[1]))
		ft_exit("Error\nThe map must be a file with a \".ber\" extension\n");
	map_check(av[1], &reading, &disp);
	disp.pos[0] = reading.pos[0];
	disp.pos[1] = reading.pos[1];
	disp.to_collect = reading.collectible;
	disp.move_count = 0;
	disp.mlx = mlx_init();
	if (!disp.mlx)
		return (1);
	disp.win = mlx_new_window(disp.mlx, reading.length * 50,
			reading.height * 50, "So long, and thanks for all the bananas !");
	create_imgs(&disp);
	put_imgs(&disp, &reading, av[1]);
	mlx_hook(disp.win, 2, 1L << 0, key_hook, &disp);
	mlx_hook(disp.win, 17, 1L << 17, ft_exit_mlx, &disp);
	mlx_loop(disp.mlx);
	return (0);
}
