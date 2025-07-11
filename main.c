#include "game.h"

void	start_window(void *mlx, void *window)
{
	int		img_width = 42;
	int		img_height = 42;
	void	*img;
	img = mlx_xpm_file_to_image(mlx, "tmp_assets/test_start.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, window, img, img_width, img_height);
	mlx_destroy_image(mlx, img);
}

void	free_data(t_data *data)
{
	if (!data)
		return;
	if (data->images)
	{
		if (data->images->img_floor)
			mlx_destroy_image(data->mlx, data->images->img_floor);
		if (data->images->img_wall)
			mlx_destroy_image(data->mlx, data->images->img_wall);
		if (data->images->img_player)
			mlx_destroy_image(data->mlx, data->images->img_player);
		free(data->images);
	}
	if (data->map)
	{
		int i = 0;
		while (data->map->map && data->map->map[i])
			free(data->map->map[i++]);
		free(data->map->map);
		free(data->map);
	}
	free(data);
}

int	loop_kill(t_data *data)
{
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_data(data);
	exit(0);
}


int	handle_input(int keycode, t_data *data)
{
	if (keycode == 65307) // ESC
		loop_kill(data);
	else if (keycode == 119)
		move_player(data, 0, -1);
	else if (keycode == 115)
		move_player(data, 0, 1);
	else if (keycode == 97)
		move_player(data, -1, 0);
	else if (keycode == 100)
		move_player(data, 1, 0);
	return (0);
}

char	**load_map(const char *filename)
{
	int		fd;
	int		line_count;
	char	**map;

	line_count = count_lines(filename);
	if (!line_count)
		return (0);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	fd = open_map_file(filename);
	if (fd == -1)
	{
		free(map);
		return (NULL);
	}
	read_map_lines(fd, map);
	close(fd);
	return (map);
}

int	init_game(t_data *data)
{
	data->images->img_player = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm",
			&data->img_width, &data->img_height);
	if (!data->images->img_player)
		return (0);
	data->images->img_wall = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",
			&data->img_width, &data->img_height);
	if (!data->images->img_wall)
		return (0);
	data->images->img_floor = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm",
			&data->img_width, &data->img_height);
	if (!data->images->img_floor)
		return (0);
	data->map->map = load_map()
	return (1);
}

int	main(void)
{
	t_data	*data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	memset(data, 0, sizeof(t_data));

	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->window = mlx_new_window(data->mlx, 1280, 720, "Game");
	if (!data->window)
		return (1);
	start_window(data->mlx, data->window);
	mlx_key_hook(data->window, handle_input, data);
	
	mlx_loop(data->mlx);
	return (0);
}
