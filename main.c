#include <libc.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <stdbool.h>
#define KEY_UP 13
#define KEY_LEFT 0
#define KEY_DOWN 1
#define KEY_RIGHT 2

struct IMG
{
	void *wall_img;
	void *floor_img;
	void *player_img;
	void *collection_img;
	void *exit_img;
};

struct s_game
{
	char **map;
	int player_x;
	int player_y;
	int floor_x;
	int floor_y;
	int key_code;
	void *mlx_ptr;
	void *win_ptr;
	size_t collect_count;
	struct IMG img;
};

char *get_next_line(int fd)
{
    int 	i = 0;
    int 	rd = 0;
    char	character;
    char 	*buffer = malloc(10000);

    while ((rd = read(fd, &character, 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    if ((!buffer[i - 1] && !rd) || rd == -1)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] =  '\0';
    return(buffer);
}

char **input_map(char *file_name)
{

	int fd;
	fd = open(file_name, O_RDONLY);
	char **map;
	map = (char**)malloc(sizeof(char*) * 100);
	map[0] = get_next_line(fd);
	int i = 0;
	while(map[i] != NULL)
	{
		i++;
		map[i] = get_next_line(fd);
	}
	return (map);
}

void display_grid(void *mlx_ptr, void *win_ptr, struct IMG img, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.wall_img, x, y);
	if (tile == '0')
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.floor_img, x, y);
	if (tile == 'C')
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.collection_img, x, y);
	if (tile == 'E')
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.exit_img, x, y);
}

void display_img(struct s_game *game)
{
	int bufx = 0;
	int bufy = 0;

	int i = 0;
	while (game->map[i] != NULL)
	{
		int j = 0;
		while (game->map[i][j] != '\0')
		{
			display_grid(game->mlx_ptr, game->win_ptr, game->img, j * 59, i * 59, game->map[i][j]);
			j++;
		}
		i++;
	}
}

void display_player(struct s_game *game)
{
	int x;
	int y;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player_img  , game->player_x * 59, game->player_y * 59);

}

void display_floor(struct s_game *game)
{
	int x;
	int y;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor_img, game->player_x, game->player_y);
}

bool check_collision(struct s_game *game, int player_next_y, int player_next_x)
{

	if (game->map[player_next_y][player_next_x] == '1')
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

int input_key(int key_code, struct s_game *game)
{
	printf("%d\n", key_code);
	game->key_code = key_code;
	display_floor(game);
	printf("%d %d\n", game->player_x, game->player_y);
	return (0);
}

int move_player(struct s_game *game)
{
	
	if (game->key_code == KEY_UP)
	{
		if (check_collision(game, game->player_y - 1, game->player_x  ) == true)
		{
			return (0);
		}
			game->player_y = (game->player_y - 1)  ;
	}
	if (game->key_code == KEY_LEFT)
	{
		if (check_collision(game, game->player_y, game->player_x - 1) == true)
		{
			return (0);
		}
		else
			game->player_x = (game->player_x - 1)  ;
	}
	if (game->key_code == KEY_DOWN)
	{
		if (check_collision(game, game->player_y + 1, game->player_x  ) == true)
		{
			return (0);
		}
		game->player_y = (game->player_y + 1)  ;
	}
	if (game->key_code == KEY_RIGHT)
	{
		//if (player_x + 1 == "wall")
		if (check_collision(game, game->player_y, game->player_x + 1) == true)
		{
			return (0);
		}
		else
		{
			game->player_x = (game->player_x + 1)  ;
		}
	}
	game->key_code = -1;
	display_player(game);
	printf("%d %d\n", game->player_x, game->player_y);
	return (0);
}


void init_game(struct s_game *game)
{
	int bufx = 0;
	int bufy = 0;

	game->win_ptr = mlx_new_window(game->mlx_ptr, 500, 500, "mlx 42");
	game->img.wall_img = mlx_xpm_file_to_image(game->mlx_ptr, "wall.xpm", &bufx, &bufy); 
	game->img.floor_img = mlx_xpm_file_to_image(game->mlx_ptr, "floor.xpm", &bufx, &bufy);
	game->img.player_img = mlx_xpm_file_to_image(game->mlx_ptr, "player.xpm", &bufx, &bufy);
	game->img.collection_img = mlx_xpm_file_to_image(game->mlx_ptr, "collection.xpm", &bufx, &bufy);
	game->img.exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "exit.xpm", &bufx, &bufy);
}


void check_map(struct s_game *game)
{
	int i = 0;
	char **map;

	map = game->map;
	while (map[i] != NULL)
	{
		int j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
			}
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	char *file_name = argv[1];
	struct s_game *game;

	game = malloc(sizeof(struct s_game));
	game->mlx_ptr = mlx_init();
	game->map = input_map(file_name);
	check_map(game);
	init_game(game);
	display_img(game);
	mlx_key_hook(game->win_ptr, input_key, game);
	mlx_loop_hook(game->mlx_ptr, move_player, game);
	mlx_loop(game->mlx_ptr);
	//nt mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
	return (0);
}