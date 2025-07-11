#include "game.h"

void	start_window(void *mlx, void *window)
{
	int		img_width = 42;
	int		img_height = 42;
	void	*img;
	img = mlx_xpm_file_to_image(mlx, "tmp_assets/test_start.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, window, img, img_width, img_height);
}

int	loop_kill(void *param)
{
	(void)param;
	exit(0);
	return 0;
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
	data->window = mlx_new_window(data->mlx, 1280, 720, "Zanqa Game");
	if (!data->window)
		return (1);
	start_window(data->mlx, data->window);
	mlx_loop_hook(data->mlx, loop_kill, data);
	mlx_loop(data->mlx);
	return (0);
}
