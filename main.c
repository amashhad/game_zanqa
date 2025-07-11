#include "game.h"

void	start_window(void *mlx, void *window)
{
	int	x = 0, y = 0;
	void	*img;
	img = mlx_xpm_file_to_image(mlx, "tmp_asset/stest_start.xpm", &x, &y);
	mlx_put_image_to_window(mlx, window, img, x, y);
}

int	loop_kill(void *param)
{
	(void)param;
	exit(0);
	return 0;
}
int	main(void)
{
	t_data	*data;

	memset(&data, 0, sizeof(data));

	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->window = mlx_new_window(data->mlx, 1280, 720, "Game");
	if (!data->window)
		return (1);
	start_window(data->mlx, data->window);
	mlx_loop_hook(data->mlx, loop_kill, &data);
	mlx_loop(data->mlx);
	return (0);
}
