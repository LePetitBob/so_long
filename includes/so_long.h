/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:13:02 by vduriez           #+#    #+#             */
/*   Updated: 2022/01/27 18:58:53 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_read
{
	int		index;
	int		check;
	int		read_ret;
	char	*reading;
	char	*line;
}				t_read;

typedef struct s_gnl
{
	int		fd;
	char	*line;
	char	**map;
	int		length;
	int		exits;
	int		height;
	int		heightmax;
	int		player;
	int		pos[2];
	int		collectible;
	int		enemy;
	int		rect;
	int		walls;
	int		requisites;
	int		tmp;
}				t_gnl;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img_e;
	void	*img_f;
	void	*img_w;
	void	*img_c;
	void	*img_p;
	char	**map;
	char	*rp_e;
	char	*rp_f;
	char	*rp_w;
	char	*rp_c;
	char	*rp_p;
	int		pos[2];
	int		move_count;
	int		to_collect;
}				t_mlx;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_free(char *s);
char	*ft_free2(char *s, char *reste);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*ft_strndup(const char *s1, int size);

int		printable(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *s);
int		map_rectangular(t_gnl *reading);
int		extension_check(char *ext, char *file);
int		ft_exit_mlx(t_mlx *disp);
int		ft_exit_close(t_mlx *disp);

void	map_check(char *map_name, t_gnl *reading, t_mlx *disp);
void	set_map(t_gnl *reading, t_mlx *disp);
void	map_requisites(t_gnl *reading);
void	map_closed(t_gnl *reading);
void	ft_problems(t_gnl *reading, t_mlx *disp);
void	ft_exit(char *strerr);
void	reading_init(t_gnl *reading, char *map);
void	err_img(char *msg, t_mlx *disp);
void	sprite_check(t_mlx *disp, char *path);
void	create_imgs(t_mlx *disp);
void	put_imgs(t_mlx *disp, t_gnl *reading, char *map);
void	put_img_to_screen(t_gnl *reading, t_mlx *disp, int i);
void	ft_exit(char *strerr);
void	destroy_image(t_mlx *disp);
void	move_y(t_mlx *disp, int keycode);
void	move_x(t_mlx *disp, int keycode);
void	move_left(t_mlx *disp);
void	move_right(t_mlx *disp);
void	move_up(t_mlx *disp);
void	move_down(t_mlx *disp);
void	free_map(char **map);

#endif