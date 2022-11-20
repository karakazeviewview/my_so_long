/*
#include <mlx.h>
#include<unistd.h>
int some(void *p){(void)p;sleep(1);return 0;}

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	void	*img;
	int bufx;
	int bufy;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	img = mlx_xpm_file_to_image(mlx_ptr, "happy_end.xpm", &bufx, &bufy);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	mlx_loop_hook(mlx_ptr, some, 0);
	mlx_loop(mlx_ptr);
}
*/




/*
char *get_file(const char * filename)
{
	i
}

int main(int argc, char * argv[])
{
	// 1.

	char *file;

	for (size_t i = 1; i < (size_t)argc; i++)
	{
		file = get_file(argv[i]);
		printf("%s========================\n", argv[i]);
		printf("%s\n", file);
		printf("========================\n");
	}
	
	return 0;
}
*/



// 1.

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

	// 2.
	int fd;
	fd = open(file_name, O_RDONLY);


	
	
	// openの戻り値がfd

	// 3.
	char **map;
	map = (char**)malloc(sizeof(char*) * 100);
	// たての領域確保ok
	// 4.
	//get_next_line(); // gnlで行を読み込む
	map[0] = get_next_line(fd);
	//while (map[i])
	//while (map[i] != '\0')
	//while (map[i] != NULL)
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

void display_img(struct s_game game)
{
	int bufx = 0;
	int bufy = 0;

	game.win_ptr = mlx_new_window(game.mlx_ptr, 500, 500, "mlx 42");
	game.img.wall_img = mlx_xpm_file_to_image(game.mlx_ptr, "wall.xpm", &bufx, &bufy); //void_pointerを返す
	game.img.floor_img = mlx_xpm_file_to_image(game.mlx_ptr, "floor.xpm", &bufx, &bufy);
	game.img.player_img = mlx_xpm_file_to_image(game.mlx_ptr, "player.xpm", &bufx, &bufy);
	game.img.collection_img = mlx_xpm_file_to_image(game.mlx_ptr, "collection.xpm", &bufx, &bufy);
	game.img.exit_img = mlx_xpm_file_to_image(game.mlx_ptr, "exit.xpm", &bufx, &bufy);

	//mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	int i = 0;
	while (game.map[i] != NULL)
	{
		int j = 0;
		while (game.map[i][j] != '\0')
		{
			//mlx_put_image_to_window(mlx_ptr, win_ptr, wall_img, j * 59, i * 59);
			display_grid(game.mlx_ptr, game.win_ptr, game.img, j * 59, i * 59, game.map[i][j]);
			j++;
		}
		i++;
	}
	//mlx_loop_hook(mlx_ptr, some, 0);
}

//check_img(char *grid)
//{
//}

// W 87, A 65, S 83, P 80
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

//int		mlx_key_hook(void *win_ptr, int (*f)(), void *param);
//{}

void init_game(struct s_game game)
{
	//void *mlx_ptr;
	//void *win_ptr;
	int bufx = 0;
	int bufy = 0;
	//struct IMG img;

	game.win_ptr = mlx_new_window(game.mlx_ptr, 500, 500, "mlx 42");
	game.img.wall_img = mlx_xpm_file_to_image(game.mlx_ptr, "wall.xpm", &bufx, &bufy); //void_pointerを返す
	game.img.floor_img = mlx_xpm_file_to_image(game.mlx_ptr, "floor.xpm", &bufx, &bufy);
	game.img.player_img = mlx_xpm_file_to_image(game.mlx_ptr, "player.xpm", &bufx, &bufy);
	game.img.collection_img = mlx_xpm_file_to_image(game.mlx_ptr, "collection.xpm", &bufx, &bufy);
	game.img.exit_img = mlx_xpm_file_to_image(game.mlx_ptr, "exit.xpm", &bufx, &bufy);
}

//void display_windkow;

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
	struct s_game game;

	game.mlx_ptr = mlx_init();
	game.map = input_map(file_name);
	check_map(&game);
	init_game(game);
	//printf("%c\n", game.map[1][1]);
	display_img(game);
	//exit(0);
	//printf("%s", map[0]);
	/*
	int i = 0;
	while (map[i] != NULL)
	{
		i++;
		printf("%s", map[i]);
	}
	*/
	mlx_key_hook(game.win_ptr, input_key, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}