#include <mlx.h>
#include <stdlib.h>

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (!mlx)
		return (1);

	window = mlx_new_window(mlx, 69, 69, "Game");
	if (!window)
		return (1);

	mlx_hook(window, 17, 0, close_window, NULL);

	mlx_loop(mlx);
	return (0);
}
