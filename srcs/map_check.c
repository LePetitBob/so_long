/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:29:46 by vduriez           #+#    #+#             */
/*   Updated: 2022/01/27 18:29:09 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_rectangular(t_gnl *reading)
{
	int	i;

	i = 0;
	while (reading->line[i] && reading->line[i] != '\n')
		i++;
	if (i != reading->length)
		return (0);
	return (1);
}

void	map_closed(t_gnl *reading)
{
	int	i;

	i = 0;
	while (reading->line[i] && reading->line[i] != '\n')
	{
		if (reading->height == 0 || reading->height == reading->heightmax)
		{
			if (reading->line[i] != '1')
				reading->walls = 0;
		}
		else if (reading->line[0] != '1'
			|| reading->line[reading->length - 1] != '1')
			reading->walls = 0;
		i++;
	}
}

void	map_requisites(t_gnl *reading)
{
	int	i;

	if (!map_rectangular(reading))
		reading->rect = 0;
	i = 1;
	while (i < reading->length - 1)
	{
		if (reading->line[i] != '0' && reading->line[i] != '1'
			&& reading->line[i] != 'C' && reading->line[i] != 'P'
			&& reading->line[i] != 'E' && reading->line[i] != '\n')
			reading->requisites = 0;
		if (reading->line[i] == 'P')
		{
			reading->player++;
			reading->pos[0] = i;
			reading->pos[1] = reading->height;
		}
		if (reading->line[i] == 'C')
			reading->collectible++;
		if (reading->line[i] == 'E')
			reading->exits++;
		i++;
	}
	reading->height++;
}

void	map_check(char *map_name, t_gnl *reading, t_mlx *disp)
{
	reading_init(reading, map_name);
	reading->fd = open(map_name, O_RDONLY);
	if (reading->fd < 0)
		ft_exit("Error\nFailed to open map_name\n");
	set_map(reading, disp);
	reading->line = get_next_line(reading->fd);
	reading->length = ft_strlen(reading->line);
	if (reading->line && reading->line[reading->length - 1] == '\n')
		reading->length--;
	while (reading->line)
	{
		if (reading->line[0] != '\n')
		{
			map_requisites(reading);
			map_closed(reading);
			disp->map[reading->tmp++] = ft_strndup(reading->line,
					reading->length);
		}
		free(reading->line);
		reading->line = get_next_line(reading->fd);
	}
	free(reading->line);
	close(reading->fd);
	ft_problems(reading, disp);
}

void	ft_problems(t_gnl *reading, t_mlx *disp)
{
	if (reading->collectible < 1 || reading->player != 1
		|| reading->exits < 1 || !reading->requisites)
	{
		free_map(disp->map);
		ft_exit("Error\nThe map must meet the requisites (0/1/E/C/P). RTFM\n");
	}
	if (!reading->rect)
	{
		free_map(disp->map);
		ft_exit("Error\nThe map must be rectangular\n");
	}
	if (!reading->walls)
	{
		free_map(disp->map);
		ft_exit("Error\nThe map must be closed by walls\n");
	}
}
