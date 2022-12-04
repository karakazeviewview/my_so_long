/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:06:04 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/04 20:02:51 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdbool.h>
# include <fcntl.h>
# define CHECKED '*'
# define KEY_UP 13
# define KEY_LEFT 0
# define KEY_DOWN 1
# define KEY_RIGHT 2
# define IMG_WALL "img/wall.xpm"
# define IMG_PLAYER "img/player.xpm"
# define IMG_FLOOR "img/floor.xpm"
# define IMG_COLLECTION "img/collection.xpm"
# define IMG_EXIT "img/exit.xpm"

struct s_img
{
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collection_img;
	void	*exit_img;
};

struct s_game
{
	char			**map;
	size_t			step_count;
	int				map_height;
	int				map_width;
	int				player_y;
	int				player_x;
	int				key_code;
	int				player_old_y;
	int				player_old_x;
	void			*mlx_ptr;
	void			*win_ptr;
	size_t			collect_count;
	struct s_img	img;
};

void	put_err(struct s_game *game);
void	all_err_check(struct s_game *game);
char	*mini_get_next_line(int fd);
char	**input_map(char *file_name);
void	display_grid(struct s_game *game, int x, int y, char tile);
void	display_img(struct s_game *game);
int		display_player(struct s_game *game);
void	display_floor(struct s_game *game);
void	exit_game(struct s_game *game);
bool	check_collision(struct s_game *game,
			int player_next_y, int player_next_x);
int		input_key(int key_code, struct s_game *game);
int		move_player(struct s_game *game);
void	init_game(struct s_game *game);
void	check_map(struct s_game *game);
int		main(int argc, char **argv);
int		update_game(struct s_game *game);
#endif