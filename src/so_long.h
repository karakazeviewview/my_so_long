/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:06:04 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/12/11 11:51:54 by mmatsuo          ###   ########.fr       */
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

# define CLUSTER

# ifdef CLUSTER
#  define KEY_ARROW_UP 126
#  define KEY_ARROW_LEFT 123
#  define KEY_ARROW_DOWN 125
#  define KEY_ARROW_RIGHT 124
#  define KEY_ESC 53
#  define KEY_UP 13
#  define KEY_LEFT 0
#  define KEY_DOWN 1
#  define KEY_RIGHT 2
# else
#  define KEY_ARROW_UP 65362
#  define KEY_ARROW_LEFT 65361
#  define KEY_ARROW_DOWN 65364
#  define KEY_ARROW_RIGHT 65363
#  define KEY_ESC 65307
#  define KEY_UP 'w'
#  define KEY_LEFT 'a'
#  define KEY_DOWN 's'
#  define KEY_RIGHT 'd'
# endif

# define CHECKED '*'
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
	size_t			is_collect_count;
	bool			is_exit;
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

void	all_err_check(struct s_game *game);
bool	check_collision(struct s_game *game,
			int player_next_y, int player_next_x);
char	**cpy_map(struct s_game *game);
bool	check_p_e_c(char **map);
void	display_floor(struct s_game *game);
void	display_grid(struct s_game *game, int x, int y, char tile);
void	display_img(struct s_game *game);
int		display_player(struct s_game *game);
int		esc_game(struct s_game *game);
void	exit_game(struct s_game *game);
char	*ft_strchr2(const char *s, int c);
size_t	ft_strlen(const char	*str);
void	ft_write_number(int number);
void	get_map_size(struct s_game *game);
void	init_game(struct s_game *game);
int		input_key(int key_code, struct s_game *game);
char	**input_map(char *file_name);
void	load_map(struct s_game *game);
char	*mini_get_next_line(int fd);
int		move_player(struct s_game *game);
void	put_err(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		update_game(struct s_game *game);

#endif
