#include <libc.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>

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
	if (tile == 'P')
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.player_img, x, y);
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


int input_key(int key_code, struct s_game *game)
{
	printf("%d\n", key_code);
	if (key_code == 13)
		game->player_y = game->player_y - 1;
	if (key_code == 0)
		game->player_x = game->player_x - 1;
	if (key_code == 1)
		game->player_y = game->player_y + 1;
	if (key_code == 2)
		game->player_x = game->player_x + 1;
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
	mlx_loop(game->mlx_ptr);
	return (0);
}